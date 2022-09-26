#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<ii> viii;
typedef tuple <ll, ll, ll> triplet;

bool touch(ii test_standard, ii a) {
    //arrival between
     if (a.first >= test_standard.first && a.first <= test_standard.second) return true;

    //departure between
    if (a.second >= test_standard.first && a.second <= test_standard.second) return true;
   
    //arrival and departure over
    if (a.first <= test_standard.first && a.second >= test_standard.second) return true;


    return false;
}

bool isContained(ii test_standard, ii a) {
    //arrival between
    if (a.first >= test_standard.first && a.second <= test_standard.second) return true;
    return false;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    ll N, D; //number of patients, day
    cin >> N >> D;

    ll C; cin >> C; // affected number of patients  
    bool affectedlist[N];
	memset(affectedlist, 0 , sizeof(affectedlist));
    while (C--) {
        ll I; cin >> I; 
        //cout << "affected index " << I - 1 << endl;
        affectedlist[I-1] = true;
    }


    
    set<ll> list;
    vii patients;
    unordered_set<ll> healthy;
    for (ll i = 0; i < N; i ++) {
        ll arrival, departure; 
        cin >> arrival >> departure;
        patients.push_back({arrival,departure});
        healthy.insert(i);
        if (affectedlist[i]== true) {
            list.insert(i);
            healthy.erase(i);     
        }
    }
    vector<ii> range;
    vector<set<ll>> adj(N, set<ll>());
    for (ll i = 0; i < N; i ++) {
        ll min_arrival = 1e10;
        ll max_departure = -100;
        for (ll j = 0; j < N; j ++) {
            if (touch(patients[i], patients[j])) {
                min_arrival = min(min_arrival, min(patients[i].first, patients[j].first));
                max_departure= max(max_departure, max(patients[i].second, patients[j].second));
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
        range.push_back({min_arrival,max_departure});
    }
   
    for (auto &a: range) {
        cout << "arrival " << a.first << " departure " << a.second << endl;
    }

    vector<ii> affected_range;
    for (auto &index: list) {
        //cout << index;
        affected_range.push_back(range[index]);
    }


    ll counter = 0;
    set<ll> affected = list;
    for (ll d = 0 ; d < D; d ++) {
        vector<ii> updated_arange;
        //cout << " size" << affected_range.size();
        for (auto &range : affected_range) {
            //cout << "haha" << range.first << " baba" << range.second << endl;
            ii updated_range = range;
            unordered_set<ll> updated_healthy = healthy;
            for (auto &healthyperson : healthy) {
                //cout << "healthyperson " << healthyperson <<  endl;
                counter ++;
                if (isContained(range, patients[healthyperson])) {

                    //cout << "healthyperson " << healthyperson << " fucked" << range.first << range.second << endl;
                    updated_healthy.erase(healthyperson);
                    affected.insert(healthyperson);
                }
                else if (touch(range, patients[healthyperson]) ){
                    updated_range ={min(range.first, patients[healthyperson].first) , 
                            max(range.second, patients[healthyperson].second)};
                    updated_arange.push_back(updated_range);
                }

            
            }
            healthy = updated_healthy;

        }
        affected_range = updated_arange;
        //cout << "how many" << endl;
    }

    for (auto &index: affected) {
        cout << index + 1 << " ";
    }
}
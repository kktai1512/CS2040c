#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ii> vii;
typedef vector<ii> viii;

bool touch(ii test_standard, ii a) {
    //arrival between
     if (a.first >= test_standard.first && a.first <= test_standard.second) return true;

    //departure between
    if (a.second >= test_standard.first && a.second <= test_standard.second) return true;
   
    //arrival and departure over
    if (a.first <= test_standard.first && a.second >= test_standard.second) return true;


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


    //unordered_map<ll,ii> patientshash;
    //vii affectedtime; 
    set<int> list;
    vii patients;

    for (ll i = 0; i < N; i ++) {
        ll arrival, departure; 
        cin >> arrival >> departure; 
        //patientshash.insert({i, {arrival, departure}});

        patients.push_back({arrival,departure});
        if (affectedlist[i]== true) {
            //affectedtime.push_back({arrival,departure});
            list.insert(i);
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout <<patients[i].first << patients[i].second << endl;
    // }

    vector<set<int>> adj(N, set<int>());
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (touch(patients[i], patients[j])) {
                //cout << i << "j" << j << endl;
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }
   
    // for (auto &a: adj) {
    //     for (auto &b: a) {
    //         cout << b + 1 << " ";
    //     }
    //     cout << endl;
    // }
    
    set<int> affected = list;
    for (int d = 0 ; d < D; d ++) {
        set<int> curr_affected;
        for (auto &index: affected) {
            curr_affected.merge(adj[index]);
        }
        affected.merge(curr_affected);
    }
    //cout << endl;
    
    for (auto &a: affected) {
        cout << a + 1 << " ";
        
    }
  
}
   
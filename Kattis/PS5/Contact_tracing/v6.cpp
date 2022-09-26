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


    
    set<int> list;
    vii patients;
    set<int> healthy;
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
  
    vector<set<int>> adj(N, set<int>());
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (touch(patients[i], patients[j])) {
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
    
    int counter = 0;
    set<int> affected = list;
    
    for (int d = 0 ; d < D; d ++) {
        set<int> curr;
        //cout << "day" << d << endl;
        set<int> next_day_affected;
        for (auto &index: affected) {
            next_day_affected.merge(adj[index]);
            //cout <<" index affected is" << index << endl;
            counter ++;
        }
        affected.merge(next_day_affected);
        if (affected.size() == N) break;
        set_difference(healthy.begin(), healthy.end(), affected.begin(), affected.end(), inserter(curr, curr.end()));
        healthy = curr;
        if (healthy.size() == 0) break;
    }
    //cout << endl;
    // set<int> final;
    // for (auto &a: affected) {
    //     final.insert(a+1);
    // }
    for (auto &a: affected) {
        cout << a << " ";
    }

    //cout << endl << counter;
}
   //go through each day
   // go through each healthy human being
   // check healthy human being list, see if it touches any affected
   // if so, delete it from curr healthy human being, add
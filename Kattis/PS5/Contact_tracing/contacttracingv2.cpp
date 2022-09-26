#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

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



    vii patient(N,{0,0});
    ii curr_day_arr_dep = {1000,0};
    vii affectedtime; 
    vector<ll> list;

    for (ll i = 0; i < N; i ++) {
        ll arrival, departure; 
        cin >> arrival >> departure; 
        //cout << "index: " << i<< " arrival is: " << arrival<< " departure is: " << departure << endl;
        patient[i] = {arrival, departure};

        if (affectedlist[i]== true) {
           // cout << "im affected" << i << endl;
            affectedtime.push_back({arrival,departure});
            list.push_back(i+1);
        }
    }

    sort(affectedtime.begin(), affectedtime.end());


    for (ll k = 0; k < D; k++){
        vii affectedtimetemp = affectedtime;
        //go through each patient
        for (ll i = 0; i < N; i ++) {
            //go through each affected time
            for (auto &a : affectedtime) {
                //cout << "arrival " << a.first << "dep: " << a.second << endl;
                if (affectedlist[i] == true) continue;
                if (touch(a, patient[i])) {
                    list.push_back(i+1);
                    //cout << i + 1 << " " ;
                    affectedlist[i] = true;
                    affectedtimetemp.push_back(patient[i]);
                    //cout << "im pushing something";
                }
            }
            if (affectedlist[i] == true) continue;
        }
        affectedtime = affectedtimetemp;

    }

    sort (list.begin(), list.end());
    for (auto &a: list) {
        cout << a << " ";
    }
    

    


  
}
   
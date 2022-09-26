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

vector<ii> merge_intervals(vector<ii>& v) {

  if(v.size() == 0) {
    return v;
  }

  vector<ii> result;
  result.push_back({v[0].first, v[0].second});

  for(int i = 1 ; i < v.size(); i++){
    int x1 = v[i].first;
    int y1 = v[i].second;
    int x2 = result[result.size() - 1].first;
    int y2 = result[result.size() - 1].second;

    if(y2 >= x1){
      result[result.size() - 1].second = max(y1, y2);
    }
    else{
      result.push_back({x1, y1});
    }
  }
  return result;
}

ii merge (ii test_standard, ii a) {
    return {min(test_standard.first, a.first), max (test_standard.second, a.second)};
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


    unordered_map<ll,ii> patientsss;
    vii patient(N,{0,0});
    ii curr_day_arr_dep = {1000,0};
    vii affectedtime; 
    vector<ll> list;

    for (ll i = 0; i < N; i ++) {
        ll arrival, departure; 
        cin >> arrival >> departure; 
        //cout << "index: " << i<< " arrival is: " << arrival<< " departure is: " << departure << endl;
        //patient[i] = {arrival, departure};
        patientsss.insert({i, {arrival, departure}});
        if (affectedlist[i]== true) {
           // cout << "im affected" << i << endl;
            affectedtime.push_back({arrival,departure});
            list.push_back(i+1);
        }
    }

    sort(affectedtime.begin(), affectedtime.end());
    affectedtime = merge_intervals(affectedtime);
    // cout << "SUIBIU" <<endl;
    // for (auto &a : patientsss) {
    //     cout << a.first;
    // }
    // cout << "SUIBIU" <<endl;
    int counter = 0;
    for (ll k = 0; k < D; k++){
        vii affectedtimetemp = affectedtime;
        //go through each patient
        unordered_map<ll, ii> temppatient = patientsss;
        for (auto &things : patientsss) {
            
            int index = things.first;
            cout << "index is :"<< index << endl;
            //go through each affected time
            for (int i =0; i < affectedtime.size(); i ++) {
                ii a = affectedtime[i];
                counter ++;
                cout << "arrival " << a.first << "dep: " << a.second << endl;
                if (affectedlist[index] == true) {
                    temppatient.erase(index);
                    cout << "already affected" << endl;
                    continue;
                }
                if (touch(a, things.second)) {
                    list.push_back(index+1);
                    cout << "touch" << endl;
                    //cout << index + 1 << " " ;
                    affectedlist[index] = true;
                    temppatient.erase(index);
                    affectedtimetemp[i] = merge(affectedtimetemp[i], things.second);
                    // ()          
                    //cout << "im pushing something";
                }
            }
            
            if (affectedlist[index] == true) continue;
            
        }
        affectedtime = affectedtimetemp;
        sort(affectedtime.begin(), affectedtime.end());
        affectedtime = merge_intervals(affectedtime);
        patientsss = temppatient;

    }

    sort (list.begin(), list.end());
    for (auto &a: list) {
        cout << a << " ";
    }
    
    cout << endl << counter;
    


  
}
   
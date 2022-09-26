//Lets fo first subtask and last subtask!
//Tutorial id B06, Lim De Wen, Aloysius
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
#define SORT(arr) sort(arr.begin(), arr.end())

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    int N; cin >> N;

    vector<string> names;
    for (int i = 0; i < N; i ++) {
        string name; cin >> name;
        //cout << name << endl;
        names.push_back(name);
    }
    SORT(names);

    // for (auto &name : names) {
    //     cout << name << endl;
    // }


    int K; cin >> K;
    vector<string> nick_names;
    for (int i = 0; i < K; i ++) {
        string nickname; cin >> nickname;
        //cout << nickname << endl;
        nick_names.push_back(nickname);
    }
    // string a = "jason";
    // string b = "z";
    // cout << "test :" << (a>b);
    
    for (auto &nick_name : nick_names){
        string longer = nick_name;
        while (longer.length() < 10) {
            longer += "z";
        }
        //cout << longer;

        auto lb = lower_bound(names.begin(), names.end(), nick_name);
        auto ub = upper_bound(names.begin(), names.end(), longer);

        //cout << "this is :" << ub -lb ;
        //if ub-lb is 0
        if (ub - lb == 0) {
             //if only one name
            if (lb != names.end()) {
                cout << 1 << endl;
            }
            
            //if no name
            else cout << 0 << endl;
        }

        else cout << (ub-lb) << endl;
       
        // if no name
        
       // cout << "name is " << nick_name << " lower_bound: " << *lb <<" upper_bound:" << *ub<< endl;
        //if (lb == names.end()) cout << "nothing";
       

    }
}
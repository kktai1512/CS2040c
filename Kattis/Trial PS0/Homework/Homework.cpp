#include <bits/stdc++.h>
#include <numeric>
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main() {
    freopen("in.txt", "r" , stdin);
    // int lo; char dash; int hi; cin >> lo >> dash >> hi;
    // cout << hi - lo + 1 << "\n";
    
    string line; cin >> line;
    stringstream ss(line);
    string separated;
    vector<bool> to_do(1001, false);

    while (getline(ss, separated, ';')){
        if (separated.find("-") == string::npos) //no dash
            to_do[stoi(separated)] = true;
        
        else {
            stringstream ss2(separated);
            string lo, hi;
            getline(ss2, lo, '-');
            getline(ss2, hi, '-');
            for (int i = stoi(lo); i <= stoi(hi); ++i)
                to_do[i] = true;
        }   
    }

    cout << accumulate(to_do.begin(), to_do.end(),0) << "\n";

}
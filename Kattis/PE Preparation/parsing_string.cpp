#include <bits/stdc++.h>
using namespace std;

/////////main template
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 


    string line; cin >> line;
    //cout << line << endl;
    cin.ignore();
    //string a; getline(cin, a);
    //cout << "this is " << a << endl;
    stringstream ss(line);
    string separated;

    while (getline(ss, separated, ';')){
        cout << separated << endl;
        if (separated.find("-") == string::npos) //no dash
            cout << "nodash " << separated << endl;
            ///
        
        else {
            stringstream ss2(separated);
            string lo, hi;
            getline(ss2, lo, '-');
            getline(ss2, hi);
            cout << " low " << lo << " high " << hi << endl;        }   
    }


}
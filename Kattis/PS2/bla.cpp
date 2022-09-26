#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <string> full_name;
    string name;
    cin >> name;
    
    if (full_name.size() == 2) {
        cout << full_name[0] << " " << full_name [1];
    }
     if (full_name.size() == 3) {
        cout << full_name [1]<< " " << full_name [2];
    }
     if (full_name.size() == 4) {
        cout << full_name[3] << " " << full_name [0];
    }

}
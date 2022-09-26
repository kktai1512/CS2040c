#include <bits/stdc++.h>

using namespace std;

int main() {
    typedef long long ll;
    int N, t; cin >> N >> t;
    vector<int> array(N);

    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        array[i] = a;
    }
    
    sort(array.begin(), array.end());

    if (t == 1) {
        for (int i = 0 ; i < N; i ++) {
            auto ub = lower_bound(array.begin(), array.end(), 7777 - array[i]);
            if (array[i] + *ub == 7777) {
                cout << "Yes";
                return 0;
            }
        }
        cout << "No";
    }
    
    if (t == 2) {
        bool is_unique = adjacent_find(array.begin(), array.end()) == array.end();
        cout << (is_unique ? "Unique" : "Contains duplicate");

    }

    if (t == 3) {
        for (int i = 0; i < N/2; i++) {
            if (array[i] == array[i + N/2]) {
                cout << array[i];
                return 0;
            }
        }
        cout << -1;
    }   

    if (t == 4) {
        if (N%2 == 0){ // if even
            cout << array[N/2 - 1] << " " << array[N/2];
        } 
        else {
            cout << array[N/2];
        }
    }   

    if (t == 5) {
        auto lb = lower_bound(array.begin(), array.end(), 100);
        auto ub = upper_bound(array.begin(), array.end(), 999);
        for (auto i = lb; i != ub; i++){
            cout << *i << " ";
        }
    
    }   
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    typedef long long ll;
    int N, t; cin >> N >> t;
    vector<int> array(N);

    for (int i = 0; i < N; ++i){
        ll a; cin >> a;
        array[i] = a;
    }

    if (t == 1) {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = i + 1; j < N; ++ j) {
    //             //since 7777 is odd, no way x and y will be the same, hence 
    //             //this check is sufficient
    //             if (array[i] + array[j] == 7777) {
    //                 cout << "Yes";
    //                 return 0;
    //             }
    //         }
    //     }
    //     cout << "No";
    // }
        sort(array.begin(), array.end());
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
        // for (int i = 0; i < N-1; ++i) {
        //     //if found 
        //     if (find(array.begin()+i+1, array.end(), array[i]) != array.end()) {
        //         cout << "Contains duplicate";
        //         return 0;
        //     }
        // }
        // cout << "Unique";
        sort(array.begin(), array.end());
        bool is_unique = adjacent_find(array.begin(), array.end()) == array.end();
        cout << (is_unique ? "Unique" : "Contains duplicate");

    }

    if (t == 3) {
        // for (int i = 0; i < N/2 +1 ; ++i) { //count first half and some extras enough
        //     //if found print then return 0 to exit
        //     if (count(array.begin(), array.end(), array[i]) > N/2) {
        //         cout << array[i];
        //         return 0;
        //     }
        // }
        // cout << -1;

        sort(array.begin(), array.end());
        for (int i = 0; i < N/2; i++) {
            if (array[i] == array[i + N/2]) {
                cout << array[i];
                return 0;
            }
        }
        cout << -1;
    }   

    if (t == 4) {
        sort(array.begin(), array.end());
        if (N%2 == 0){ // if even
            cout << array[N/2 - 1] << " " << array[N/2];
        } 
        else {
            cout << array[N/2];
        }
    }   

    if (t == 5) {
        sort(array.begin(), array.end());
        for (int i= 0; i < N; ++i) {
            if (array[i] >=100 && array[i] <= 999) {
                cout << array[i] << " ";
            }
        }
    
    }   
}
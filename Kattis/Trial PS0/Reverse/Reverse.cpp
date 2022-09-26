#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;

int main() {
    freopen("in.txt", "r" , stdin);
    int n; cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        list[i] = a;   
    }
    for (int i = n-1; i >= 0; --i){
       cout << list[i] << "\n";
    }
}
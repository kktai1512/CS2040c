#include <bits/stdc++.h>
using namespace std;

int main() {
    int e,f,c; cin >> e >> f >> c;
    int total_empty = e + f;
    int bottles_consumed = 0;
    int recycled = 0;
    
    while (total_empty >= c) {
        recycled = total_empty/c;
        bottles_consumed += recycled;
        total_empty = total_empty%c + recycled; 
    }

    cout << bottles_consumed;
    
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int N, Q; cin >> N >> Q;
    unordered_map<int,int> id_value;
    int default_val = 0;

    for (int i = 0; i < Q; i ++) {
        string op; int val;
        cin >> op >> val;

        if (op == "PRINT"){
            //if can find
            if (id_value.find(val) != id_value.end()) {
                cout << id_value[val] << endl;
            }
            //if cannot find
            else {
                cout << default_val << endl;
            }
        }
        


        if (op == "SET"){
            int third; cin >> third;
            if (id_value.find(val) == id_value.end()) {
                id_value.insert(make_pair(val, third));
            }
            else {
                id_value[val] = third;
            }
        }

        if (op == "RESTART") {
            default_val = val;
            id_value.clear();
        }
    }
    
}
#include <bits/stdc++.h>

using namespace std;



int main() {
    freopen("in.txt", "r" , stdin);
    int N; cin >> N;
    deque<int> teque;
    string output;
    int num = 0;
  

    for (int i = 0; i < N; i ++) {
        ios::sync_with_stdio(false); cin.tie(NULL);
        string command; int x;
        cin >> command >> x;

        if (command == "push_front") {
            teque.push_front(x);
        }

        if (command == "push_back") {
            teque.push_back(x);
        }

        if (command == "push_middle") {
            teque.insert(teque.begin() + (teque.size() + 1)/2, x);
        }

        if (command == "get") {
            cout << teque[x] <<endl;
        }

    }

    // for (auto c : teque) {
    //     cout << c;
    // }
}
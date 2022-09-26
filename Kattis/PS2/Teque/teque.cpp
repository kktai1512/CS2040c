#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r" , stdin);
    int N; cin >> N;
    deque<int> teque;
    string output;
    int num = 0;
    deque<int>::iterator cursor;
    bool found_middle = false;

    for (int i = 0; i < N; i ++) {
        ios::sync_with_stdio(false); cin.tie(NULL);
        string command; int x;
        cin >> command >> x;

        if (command == "push_front") {
            teque.push_front(x);
            if (found_middle == true) {
                if (teque.size()%2 == 0 ) {// after insertion is odd 
                    prev(cursor);
                }
            }
        }
        

        if (command == "push_back") {
            teque.push_back(x);
             if (found_middle == true) {
                if (teque.size()%2 != 0 ) {// after insertion is odd {
                    advance(cursor,1);
                }
            }
        }

        if (command == "push_middle") {
            if (found_middle == false) {
                cursor = teque.begin();
                 cout << "this is before middle" << *cursor << endl; 
                
                advance(cursor, (teque.size() + 1)/2);
                cout << "this is after finding middle" << *cursor << endl; 

                found_middle = true;
            }
        
            teque.insert(cursor++, x);
            cout << "this is after inserting" << *cursor << endl; 
            if (teque.size() %2 == 0) {
                prev(cursor);
            }
        
        }

        if (command == "get") {
            cout << teque[x] <<endl;
        }

    }

    // for (auto c : teque) {
    //     cout << c;
    // }
}
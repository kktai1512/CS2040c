#include <bits/stdc++.h>

using namespace std;
//3 59

class Teque {
    int length = 0; deque<int> front, back;
    public:
        void push_back(int x) {
            back.push_back(x);
            length ++;
            if (back.size() > front.size()) {
                int first_of_back = back.front();
                back.pop_front();
                front.push_back(first_of_back);
            }
        };
        void push_middle(int x) {
            //if front == back 3 3, or 3 2
            if (front.size() >= back.size()) {
                back.push_front(x);
            }
            //if front < back 2 3
            else {
                if (front.size() < back.size()) {
                    //balance
                    int first_of_back = back.front();
                    back.pop_front();
                    front.push_back(first_of_back);
                    back.push_front(x);
                }
            }
            length++;
        };
        void push_front(int x) {
            front.push_front(x);
            length++;
            // 3 2 is ok, 4 2 is not ok, this ensures front is always >= back
            if (front.size() > back.size()) {
                int last_of_front = front.back();
                front.pop_back();
                back.push_front(last_of_front);
            }
            length ++;
        };
        // 0 1 2 3 4 5 0 1 2 3 4 5
        int get(int x) {
            if (x >= 0 && x < front.size()) {
                return front[x];
            }
            if (x >= front.size()  && x < length) {
                return back[x-front.size()];
            }
            
            return 0;
        }

};


int main() {
    freopen("in.txt", "r" , stdin);
    int N; cin >> N;
    Teque teque;
    string output;
  

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
            teque.push_middle(x);
        }

        if (command == "get") {
            cout << teque.get(x) <<endl;
        }

    }
}
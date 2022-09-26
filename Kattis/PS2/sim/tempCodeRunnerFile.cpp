#include <bits/stdc++.h>

using namespace std;


int main() {
    int n; cin >> n; cin>> ws; // stream out white space

    for (int i = 0; i < n; i ++) {
        string line; getline(cin, line);
        // cout << line;
        list<char> output;
        list<char>::iterator cursor;

        // if abc, cursor is after a b c __
        // when we delete, we move temp cursor to c, real cursor to b;
        for (auto c : line){
            if (c == '<') {
                list<char>::iterator temp;
                temp = cursor;
                //if at start do nothing
                if (temp == output.begin()) {
                    continue;
                }
                // move backwards once for the other cursor
                if (output.size() != 0){
                    output.erase(--temp);
                }
                continue;
            }
            if (c == '[') {
                cursor = output.begin();
                continue;
            }
            if (c == ']') {
                cursor = output.end();
                continue;
            }
            if (output.size() == 0) {
                output.push_back(c);
                cursor=output.begin();
                //set cursor after first word, for example a _
                cursor ++;
                continue;
            }
        
            //insert at cursor -- > a _ ---> a b _ (cursor still infront)
            output.insert(cursor, c);

        }
        for (auto c : output) {
            cout << c << endl;
        }
    }
}
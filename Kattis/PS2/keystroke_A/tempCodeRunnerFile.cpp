#include <bits/stdc++.h>

using namespace std;

//iLnLnLeLb
// add


int main() {
    string line; cin >> line;
    list<char> output;
    list<char>::iterator cursor;

    // if abc, cursor is after a b c __
    // when we delete, we move temp cursor to c, real cursor to b;
    for (auto c : line){
        if (c == 'B') {
            list<char>::iterator temp;
            temp = cursor;
            // move backwards once for the other cursor
            output.erase(--temp);
            continue;
        }
        if (c == 'L') {
            cursor --;
            continue;
        }
        if (c == 'R') {
            cursor ++;
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
        cout << c;
    }

}
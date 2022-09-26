#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
    int N, t; cin >> N >> t;
    
    int A[N];

    for (int i = 0; i < N; i++){
        int a; cin >> a;
        A[i] = a;
    }

    if (t == 1) {
        cout << 7;
    }
    else if (t ==2) {
        if (A[0] > A[1]) {
            cout << "Bigger";
        } 
        else if (A[0] == A[1]) {
            cout << "Equal";
        }
        else 
            cout << "Smaller";
    }

    if (t==3) { // median
        int temp[] = {A[0], A[1], A[2]};
        sort(temp, temp + 3);
        cout << temp[1];
    }

    if (t==4) { // sum all numbers
        long long sum = 0;
        for (int i = 0; i < N; i ++) {
            sum += A[i];
        }
        cout << sum;
    }

    if (t==5) { // sum all even numbers
        long long sum = 0;
        for (int i = 0; i < N; i ++) {
            if (A[i] % 2 == 0) {
                sum += A[i];
            }
        }
        cout << sum;
    }

    if (t ==6) { // modulo by 26 and map to string
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string answer = "";
        for (int i = 0; i < N; i ++) {
            answer += alphabet[A[i] % 26];
        }
        cout << answer ;
    }

    if (t == 7) {
        int i = 0; // start with i = 0
        int cur_pos = A[0]; // jump to whatever A[0] is pointing at
        // initialise a vector with all zeroes, all position never visited before
        vector<int> times_visited(N,0);

        while (cur_pos != N-1) { 
            //check if out of range
            if (cur_pos < 0 || cur_pos > N-1) {
                cout << "Out";
                return 0;
            }
            //check if went before (ie in visited)
            if (cur_pos == 0 || times_visited[cur_pos] != 0){
                cout << "Cyclic";
                return 0; 
            }
            // ok, go to that position and update it to visited
            times_visited[cur_pos] += 1; 
            // go to a new position
            cur_pos = A[cur_pos];
        }

        //if exits loop means cur_pos == N-1 , then print Done and exit
        cout << "Done";
        return 0;
    }
}
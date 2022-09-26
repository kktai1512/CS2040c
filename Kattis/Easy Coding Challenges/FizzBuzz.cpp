#include <iostream>
using namespace std;

int main() {
    int X, Y, N;
    cin >> X;
    cin >> Y;
    cin >> N;

    for (int i  = 1; i <= N; i ++) {
        if (i % X == 0 && i % Y == 0) {
            cout << "FizzBuzz" << endl;
            continue;
        }
        if (i % X == 0) {
            cout << "Fizz" << endl;
            continue;
        }
        if (i % Y == 0) {
            cout << "Buzz" << endl;
            continue;
        }
        cout << i << endl;

    }
}
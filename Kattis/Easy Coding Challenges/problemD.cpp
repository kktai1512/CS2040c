#include <iostream>
using namespace std;

int main() {
    int totalTests, a, b , c;
    cin >> totalTests;
    string output[totalTests];
    for (int i = 0; i < totalTests; i++) {
        cin >> a;
        cin >> b;
        cin >> c;
        if (a+b == c || a - b == c || b - a == c || a * b == c || (double) a/b == c || (double) b/a == c) {
            output[i] = "Possible";
            continue;
        }  
        output[i] = "Impossible";
    }

    for (int i = 0; i < totalTests; i ++) {
        cout << output[i] << endl;
    }
}
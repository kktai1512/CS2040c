#include <iostream>

using namespace std;

int main() {
    int total, easy, medium, hard;
    cin >> easy;
    cin >> medium;
    cin >> hard;
    cin >> total;

    //check all at least have one or more, then check it can form total questions
    if (easy < 1 || medium < 1 || hard < 1 || easy+medium+hard < total || total < 3) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}
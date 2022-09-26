#include <iostream>
using namespace std;

int main() {

    int monthly, numOfM;
    cin >> monthly;
    cin >> numOfM;

    int remainder = 0;

    for (int i = 0; i < numOfM; i++) {
        int used_this_month;
        cin >> used_this_month;
        remainder += (monthly - used_this_month);
    }

    cout << remainder + monthly;

}
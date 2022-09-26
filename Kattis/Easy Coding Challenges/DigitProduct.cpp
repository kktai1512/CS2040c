#include <iostream>

using namespace std;
int multiplier(int number);

int main() {
    int x = 0;
    cin >> x;

    while (x >= 10) {
      x = multiplier(x);
    }

    cout << x;

}

int multiplier (int number) {
    if (number == 0) {
        return 0;
    }
    int cumulative = 1;
    int temp = 0;
    
    while (number > 0) {
        int temp = number % 10;
        number = number/10;
        if (temp == 0) {
            continue;
        }
        cumulative = cumulative * temp;
    }

    return cumulative;
}
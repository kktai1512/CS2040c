#include <iostream>
using namespace std;
int main()
{
    string hey_input;
    cin >> hey_input;
    string iniE;
    int numOfE;
    for (int i = 0; i < hey_input.length(); i++) {
        if (hey_input[i]== 'e') {
            iniE += "ee";
        }
    }
    
    cout << 'h' + iniE + 'y';

}
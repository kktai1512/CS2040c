#define _CRT_SECURE_NO_WARNINGS // to allow freopen in Visual Studio (see below)
//#include <bits/stdc++.h> // don't use in Visual Studio
#include <iostream> // brokenswords
using namespace std;
int main() {
  // freopen("in.txt", "r", stdin); // I have shown you a technique to avoid retyping (or re-pasting sample input/own tc)
  int N; cin >> N;
  int num_TB = 0, num_LR = 0;
  while (N--) {
    string s; cin >> s;
    num_TB += (s[0] == '1') + (s[1] == '1'); // submitting this code verbatim surely WA... so don't...
    num_LR += (s[2] == '1') + (s[3] == '1');
    // cout << "s is = '" << s << "'" << num_TB << " " << num_LR << "\n"; // for debugging
  }
  int new_sword = min(num_TB, num_LR) / 2; // the upper bound of new swords that can be made
  cout << new_sword << " " << num_TB - 2 * new_sword << " " << num_LR - 2 * new_sword << "\n";
  return 0;
}
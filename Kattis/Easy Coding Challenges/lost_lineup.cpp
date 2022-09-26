#include <bits/stdc++.h> // lostlineup
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> ans(n);
  ans[0] = 1; // Jimmy (person 1) is the first in line
  for (int i = 2; i <= n; ++i) { // for the other persons
    int d; cin >> d; // d = how many person(s) between person i and Jimmy (person 1)
    ans[d+1] = i; // put person i there
  }
  for (auto p : ans) {// what is this?
    cout << p << " "; // will the line ends with an extra " "? is it forgiven by Kattis?
  }
  cout << "\n"; // why "\n" not endl?
  return 0;
  std::vector<int> v = {1,2,3};
}
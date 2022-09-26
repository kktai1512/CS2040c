#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> mapper = {{"Z", 2040}, {"Steven", 7}, {"AAAAA", 10}};
  for (auto &[k, v] : mapper)
    cout << k << "->" << v << "\n";
  return 0;
}
#include <bits/stdc++.h> // tarifa
using namespace std;
int main() {
 int X; scanf("%d", &X); // huh? can we use C scanf in a C++ code?
 int N; scanf("%d", &N);
 int ans = X;
 while (N--) { // I think this has not been discussed, what is this?
   int P; scanf("%d", &P);
   cout << "N is " << N << "\n";
   ans -= P;
   ans += X; // what is '-=' ?
 }
 printf("%d\n", ans); // and similarly C printf
 return 0;
}
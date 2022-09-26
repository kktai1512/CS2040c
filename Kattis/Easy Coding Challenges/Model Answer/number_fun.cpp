#include <bits/stdc++.h> // numberfun
using namespace std;
int main() {
 int N; scanf("%d", &N);
 while (N--) {
   int a, b, c; scanf("%d %d %d", &a, &b, &c);
   printf((a+b == c) || (a-b == c) || (b-a == c) ||
    (a*b == c) || (a%b == 0 && a/b == c) || (b%a == 0 && b/a == c) 
    ? "Possible\n" : "Impossible\n"); 
   // uh this ternary condition line again... btw how many of you got RTE first before realizing that division by zero can occur?
 }
 return 0;
}
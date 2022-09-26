#include <bits/stdc++.h> // sifferprodukt
using namespace std;

int digit_product(int x) { // this can be made into a simple function
 int ans = 1;
 while (x) { // again, what is this? :O
   if (x%10 != 0) ans *= (x%10); // if last digit is not 0, multiply it
   x /= 10;
 }
 return ans;
}

int main() {
 int x; cin >> x;
 while (x > 9) // simulate
   x = digit_product(x);
 cout << x << "\n"; // why "\n" not endl?
 return 0;
}
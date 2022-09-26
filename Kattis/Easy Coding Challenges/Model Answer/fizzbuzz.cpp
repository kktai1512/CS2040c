#include <bits/stdc++.h> // fizzbuzz, a popular Interview question (in the past, now overused)
using namespace std;
int main() {
 int X, Y, N; scanf("%d %d %d", &X, &Y, &N);
 for (int i = 1; i <= N; ++i) {
   if ((i%X == 0) && (i%Y != 0))
     printf("Fizz\n");
   else if ((i%X != 0) && (i%Y == 0))
     printf("Buzz\n");
   else if ((i%X == 0) && (i%Y == 0))
     printf("FizzBuzz\n");
   else
     printf("%d\n", i);
 }
 return 0;
}
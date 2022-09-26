#include <bits/stdc++.h>
using namespace std;

int add(int *a)
{

    int b = *a + 1; //1. dereference the pointer and increment the value by 1

    *a = 5; //2. modify the value of the variable

    return b; //3. return the value of b
}

int foo(int &a) {
    int b = 5 + a;
    a = 9;
    return b;
}


int boo(int a) {
    int b = 5 + a;
    a = 9;
    return b;
}

int main() {
    int d = 3;
    int* e = &d;
    
    // cout << add(e)<< endl;
    // cout << d <<endl;
    // cout << foo(d);
    // cout << d;
    cout << boo(d);
    cout << d;  
    
}
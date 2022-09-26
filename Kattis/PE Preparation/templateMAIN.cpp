#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


#include <bits/stdc++.h>
using namespace std;

/////////main template
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 
    vi hello;

    REP(i, 10) {
        hello.push_back(i);
        cout << i;
    }

    FOREACH(it, hello) {
        cout << *it;
    }
}


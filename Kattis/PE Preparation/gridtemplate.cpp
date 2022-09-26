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
// iterative BFS version
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//supposed you have a R x C grid..
	int R,C;
	// initialisa visit to all false
	bool vist [R][C];
	memset(vist, 0 , sizeof(vist));
	queue<ii> q; // use stack for DFS
	//suppose you start at 0,0
	q.push({0,0});
	// the usual 4 directions, can change depending on context 
	vi cdir = {0,0,-1,1};
	vi rdir = {1,-1,0,0};
	while (!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int newr = r + rdir[i];
			int newc = c + cdir[i];
			//check if within bounds (can further check for stuff (if cell is accessible etc depending on context))
			if (newr<0 || newr>=R ||newc <0 || newc >=C) continue;
			//check if visited
			if (vist[newr][newc])continue;
			// you can also do other stuff here if required depdning on question, keeping track of distance etc
			vist[newr][newc] = true;
			q.push({newr,newc});
		}
	}
}
// practice problem:
// https://open.kattis.com/problems/escapewallmaria

// addition resources:
// https://usaco.guide/silver/dfs?lang=cpp
// https://usaco.guide/silver/flood-fill?lang=cpp
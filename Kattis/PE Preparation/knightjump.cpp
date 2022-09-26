#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = (int)1e9;
/////////main template
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    
    int N; cin >> N;
    ii curr_pos = {0,0};
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'K') curr_pos = {i,j};
            
        } 
    }
    cout << curr_pos.first << curr_pos.second;

    bool vist [N][N];
	memset(vist, 0 , sizeof(vist));
	queue<ii> q; // use stack for DFS
	//suppose you start at 0,0
	q.push(curr_pos);
	// the usual 4 directions, can change depending on context 
    vi rdir = {2, 2, -2, -2, 1, 1, -1, -1};
	vi cdir = {1, -1, 1, -1 , 2, -2, 2, -2};
    vector<vector<int>> distance (N, vector<int>(N,INF));
    distance[curr_pos.first][curr_pos.second] = 0;

	int counter = 0;
	while (!q.empty()) {
		auto [r,c] = q.front(); q.pop();
        counter += 1;
		for(int i = 0; i < 8; i++) {
			int newr = r + rdir[i];
			int newc = c + cdir[i];
			//check if within bounds (can further check for stuff (if cell is accessible etc depending on context))
			if (newr<0 || newr>=N ||newc <0 || newc >=N) continue;
			//check if visited
			if (vist[newr][newc])continue;
			// you can also do other stuff here if required depdning on question, keeping track of distance etc
			vist[newr][newc] = true;
            distance[newr][newc] = distance[r][c] + 1;
            if (newr == 0 && newc == 0) cout << "reached";
			q.push({newr,newc});
		}
	}
    cout <<"IMPOSSIBLE";
    if (distance[0][0] == INF) cout << "NO";
    else cout <<distance[0][0];
}
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int INF = (int)1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    int N, M; cin >> N >> M;
    vector<vector<ii>>  adj (N, vector<ii>());
    for (int i = 0; i < M; i ++){
        int a, b, c; 
        cin >> a >> b >> c; a--; b--; 
        //cout << a << " " << b << " " << c << " " << endl;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<vector<int>> distance (N, vector<int>(N,INF));
   
    bool visited[N];
    memset(visited, 0 , sizeof(visited));
	queue<int> q;
    q.push(0);
    vector<int> d(N, INF);
    d[0] = 0;
    visited[0] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto u : adj[v]) {
            if (!visited[u.first]) {
                visited[u.first] = 1;
                q.push(u.first);
                d[u.first] = d[v] + u.second;
            }
            if (visited[u.first]) continue;
        }

    } 

    for (int i = 0; i < N; i ++) {
        cout << d [i] << " " ;
    }

	cout << endl << d[N-1];
}


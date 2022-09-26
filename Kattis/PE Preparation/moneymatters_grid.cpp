#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;cin>>n>>m;
    vector<int> ownarr(n);
    for (int i =0; i < n; i++) {
        cin>>ownarr[i];
    }
    vector<vector<int>> adj(n, vector<int>());
    for (int i= 0; i < m; i++) {
        int u,v;cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bool able = true;
    bool vist[n];
    memset(vist, 0, sizeof(vist));
    for (int i = 0; i < n; i++) {
        if (vist[i])continue;
        queue<int> q;
        int totval = ownarr[i];
        vist[i] = true;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u]) {
                if (vist[v]) continue;
                q.push(v);
                totval += ownarr[v];
                vist[v] = true;
            }
        }
        if (totval != 0) able = false;
    }
    cout<<(able?"POSSIBLE" :"IMPOSSIBLE");

}
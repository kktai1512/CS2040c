#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    vector<int> moneylist;
   
    int N, M; cin >> N >> M;
    for (int i = 0 ; i < N ; i ++ ) {
        int money; cin>> money;
        cout << money << endl;
        moneylist.push_back(money);
    }
     vector<vector<int>> friendslist(N, vector<int>());
    for (int i = 0; i < M; i ++) {
        int a, b; cin >> a >> b; 
        friendslist[a].push_back(b);
        friendslist[b].push_back(a);
    }
    bool visit[N];
	memset(visit, 0 , sizeof(visit));
	 // use stack for DFS

    for (int i = 0; i < N; i ++) {
        if (visit[i]) continue;
        queue<int> q;
        q.push(i);
        int amount = moneylist[i];
        visit[i] = true;
        while (!q.empty()) {
		    int u = q.front(); q.pop();
		for(int j = 0; j < friendslist[u].size(); j++) {
            if (visit[friendslist[u][j]]) continue;
            visit[friendslist[u][j]] = true;
            amount += moneylist[friendslist[u][j]];
            q.push(friendslist[u][j]);
        }

        }
        if (amount != 0) cout << "cannot";
    }

  

    
}
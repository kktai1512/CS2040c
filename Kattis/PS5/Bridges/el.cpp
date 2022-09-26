#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int> edge;
typedef vector<int> vi;
const int INF = (int)1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r" , stdin); 

    int N, M; cin >> N >> M;
    vector<edge> EL;
    for (int i = 0; i < M; i ++){
        int a, b, c; 
        cin >> a >> b >> c; a--; b--; 
        //cout << a << " " << b << " " << c << " " << endl;
        EL.push_back({a, b, c});
        EL.push_back({b, a, c});
    }
    vi dist(N, INF);
    dist[0] = 0;


    for (int i = 0; i < N-1; ++i) { // n-1 rounds
    bool got_relaxation = false;
      for (auto& [u, v, w] : EL) { // for all m edges
        //cout << "u" << u+1 << " v" << v+1 << " w" << w<<  endl;
        if (dist[u] == INF) continue; // special check to avoid propagating INF
        if (dist[u]+w >= dist[v]) continue;
        dist[v] = dist[u]+w;
        // if (v == 9) {
          //cout << "ALERT!!!!" << endl;
        // }
        got_relaxation = true;
        //cout << "im doing" << endl;
        //cout << "debug " << "v " << v+1 << " " << dist[v] << endl;
      }
       if (!got_relaxation)
        break; 
      //cout << "hello";
    }
    //cout << dist[5];
    cout << dist[N-1];
    //cout << M;
}


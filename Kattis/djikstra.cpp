#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

int main() {
  /*
  // Graph in Figure 4.17
  5 7 0
  0 1 2
  0 2 6
  0 3 7
  1 3 3
  1 4 6
  2 4 1
  3 4 5
  */

  freopen("in.txt", "r", stdin);

  int V, E, s; scanf("%d %d %d", &V, &E, &s);
  vector<vii> AL(V, vii());
  while (E--) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    AL[u].emplace_back(v, w);                    // directed graph
  }

  vi dist(V, INF); dist[s] = 0;                  // INF = 1e9 here

  // Original Dijkstra's algorithm
  
  set<ii> pq;                                    // balanced BST version
  for (int u = 0; u < V; ++u)                    // dist[u] = INF
    pq.insert({dist[u], u});                     // but dist[s] = 0

  // sort the pairs by non-decreasing distance from s
  while (!pq.empty()) {                          // main loop
    auto [d, u] = *pq.begin();                   // shortest unvisited u
    cout << " d " << d << " u " << u << endl;
    pq.erase(pq.begin());
    for (auto &[v, w] : AL[u]) {                 // all edges from u
      cout << "visiting neighbours " << v << endl;
      if (dist[u]+w >= dist[v]) continue;        // not improving, skip
      cout << dist[v] << endl;
      if (pq.find({dist[v], v})!= pq.end()) pq.erase(pq.find({dist[v], v}));           // erase old pair;
      dist[v] = dist[u]+w;                       // relax operation
      pq.insert({dist[v], v});  
      cout << "inserting " << dist[v] <<  " v " << v <<endl;                 // enqueue better pair
    }
  }
  

  // (Modified) Dijkstra's algorithm
//   priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push({0, s});

//   // sort the pairs by non-decreasing distance from s
//   while (!pq.empty()) {                          // main loop
//     auto [d, u] = pq.top(); pq.pop();            // shortest unvisited u
//     if (d > dist[u]) continue;                   // a very important check
//     for (auto &[v, w] : AL[u]) {                 // all edges from u
//       if (dist[u]+w >= dist[v]) continue;        // not improving, skip
//       dist[v] = dist[u]+w;                       // relax operation
//       pq.push({dist[v], v});                     // enqueue better pair
//     }
//   }

  for (int u = 0; u < V; ++u)
    printf("SSSP(%d, %d) = %d\n", s, u, dist[u]);

  return 0;
}
#include <bits/stdc++.h>

using namespace std;
// example graph, expect 0 4 3 5 9
/*
5 7
0 1 7
0 2 3
1 2 1
1 3 2
1 4 6
2 3 2
3 4 4
*/
int n, m; // n nodes, m edges
vector<pair<int, int> > adj[100]; // adjacency list
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // min priority queue
int dist[100]; // distances

int main(){
  // read in data
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y, l;
    cin >> x >> y >> l;
    adj[x].push_back({l, y});
    adj[y].push_back({l, x});
  }
  // set all as unvisited
  for(int i = 0; i < n; i++){
    dist[i] = -1;
  }
  pq.push({0, 0}); // starting pt

  while(!pq.empty()){
    pair<int,int> dv;
    dv = pq.top();
    pq.pop();
    if(dist[dv.second] == -1){
      dist[dv.second] = dv.first;
      for(pair<int,int> j : adj[dv.second]){
        if(dist[j.second] == -1){
          pq.push({dv.first + j.first, j.second});
        }
      }
    }
  }
  for(int i = 0; i < n; i++){
    cout << dist[i] << endl;
  }
  return 0;
}
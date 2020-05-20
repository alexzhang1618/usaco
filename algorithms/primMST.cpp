#include <bits/stdc++.h>

using namespace std;

// example graph, expect 10
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

int n, m;
vector<pair<int,int> > adj[100]; // adjacency list
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // Priority queue of pairs
int dist[100]; // distances, -1 means unreachable

int main(){
  // read in everything
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y, l;
    cin >> x >> y >> l;
    adj[x].push_back({l, y});
    adj[y].push_back({l, x});
  }

  // set everything as unvisited
  for(int i = 0; i < n; i++){
    dist[i] = -1;
  }

  pq.push({0, 0}); // starting pt
  
  int mst_len = 0;
  while(!pq.empty()){
    pair<int, int> dv = pq.top();
    pq.pop();
    if(dist[dv.second] == -1){ // if not visited
      dist[dv.second] = dv.first;
      mst_len += dv.first;
      for(pair<int,int> j : adj[dv.second]){
        if(dist[j.second] == -1)
          pq.push({j.first, j.second});
      }
    }
  }
  cout << mst_len << endl;
  return 0;
}
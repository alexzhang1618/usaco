#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, pair<int, int> > > graph;
int parent[100];
int dist[100];

int find(int v){
  //Union find - finds the head node
  if(parent[v] == v)
    return v;
  return find(parent[v]);
}

void combine(int v, int w){
  //Finds head node of two vertices, checks smallest distance, then combines
  int findv = find(v);
  int findw = find(w);
  if(dist[findv] > dist[findw]){
    parent[findw] = findv;
  }
  else{
    parent[findv] = w;
    dist[findw] = max(dist[findw], dist[findv] + 1);
  }
}

int main(){
  for(int i = 0; i < 100; i++){
    parent[i] = i;
    dist[i] = 0;
  }
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y, l;
    cin >> x >> y >> l;
    graph.push_back({l, {x, y}});
  }
  sort(graph.begin(), graph.end());
  int c = 0, i = 0, tot = 0; // c is counter for edges added, i is current edge
  while(i < graph.size() && c < n - 1){
    pair<int, pair<int,int> > curedge = graph[i];
    int l = curedge.first;
    int x = curedge.second.first;
    int y = curedge.second.second;
    if(find(x) != find(y)){ // if edge added without cycle
      c++;
      tot += l;
      combine(x, y);
    }
    i++;
  }
  cout << tot << endl;
  return 0;
}
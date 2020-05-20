// depth first search
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100]; // adjacency list
bool visited[100];
stack<int> s; // for iterative DFS

void dfs_rec(int node = 0){
  // Recursive DFS
  if(visited[node])
    return;
  visited[node] = true;
  for(int i: adj[node]){
    if(!visited[i]){
      //here's where you use it for something
      dfs_rec(i);
    }
  }
}

void dfs_iter(){
  // Iterative DFS, needs a stack and thus more space
  s.push(0);
  while(!s.empty()){
    int current = s.top();
    if(!visited[current]){
      visited[current] = true;
      s.pop(); // remove it from being checked
      for(int i : adj[current]){
        if(!visited[i])
          //here's where you use it for something
          s.push(i);
      }
    }
  }
}
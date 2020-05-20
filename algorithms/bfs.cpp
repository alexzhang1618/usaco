// breadth first search
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100]; // adjacency list
bool visited[100];
queue<int> q;

void bfs() {
  q.push(0);
  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(int i: adj[current]){
      if(!visited[i]){
        q.push(i);
        visited[i] = true;
      }
    }
  }  
}
#include <bits/stdc++.h>

using namespace std;

const int n = 100005;

char col[n];
vector<int> adj[n];
int N, M, num = 0, comp[n];

void dfs(int x){
  if(comp[x])
    return;
  comp[x] = num;
  for(int t: adj[x]){
    if(col[x] == col[t])
      dfs(t);
  }
}

int main(){
  ifstream cin("milkvisits.in");
  ofstream cout("milkvisits.out");
  cin >> N >> M;
  string name;
  cin >> name;
  for(int i = 1; i < N + 1; i++){
    col[i] = name[i - 1];
  }

  for(int i = 0; i < N - 1; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i = 1; i < N + 1; i++){
    if(!comp[i]){
      //new component
      num++;
      dfs(i);
    }
  }

  for(int i = 0; i < M; i++){
    int x, y;
    char pref;
    cin >> x >> y >> pref;
    if(col[x] == pref || comp[x] != comp[y])
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
  return 0;
}

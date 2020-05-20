#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> check;
int rv[1005];
bool visited[1005];
bool finished = false;

void dfs(int layer, int i){
  if(layer == N - 1){
    finished = true;
    return;
  }
  if(visited[i])
    return;
  visited[i] = true;
  for(int j = 1; j <= N; j++){
    if(!visited[j] && i + j == check[layer]){
      rv[layer] = i;
      rv[layer + 1] = j;
      dfs(layer + 1, j);
    }
  }
  visited[i] = false;
}

int main(){
  ifstream cin("photo.in");
  ofstream cout("photo.out");
  cin >> N;
  for(int i = 0; i < N - 1; i++){
    int a; cin >> a;
    check.push_back(a);
  }
  for(int i = 1; i <= N; i++){
    dfs(0, i);
    if(finished)
      break;
  }
  for(int i = 0; i < N; i++){
    if(i == 0)
      cout << rv[i];
    else
      cout << " " << rv[i];
  }
  cout << endl;
  return 0;
}

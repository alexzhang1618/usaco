#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1005;
char grid [1005][1005];
bool visited [1005][1005];
int perimeter [1005];
int area [1005];
int pointer = 0;

void dfs(int x, int y, int layer){
  if(!visited[x][y])
    return;
  visited[x][y] = true;
  if(grid[x][y] == '.')
    return;
  
}

int main(){
  ifstream cin("perimeter.in");
  ofstream cout("perimeter.out");
  cin >> N;
  for(int i = 0; i < N; i++){
    string line; cin >> line;
    for(int j = 0; j < N; j++)
      char[i][j] = line[j];
  }

}

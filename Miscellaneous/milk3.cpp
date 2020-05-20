/*
ID: alexzha5
TASK: milk3
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> end_val;
int cap[3];
int visited[23][23][23];

void dfs(int a, int b, int c){
  if(visited[a][b][c])
    return;
  visited[a][b][c] = true;
  if(a == 0){
    end_val.push_back(c);
  }

  int amount_pour;
  //pour a into b
  amount_pour = min(a, cap[1] - b);
  dfs(a - amount_pour, b + amount_pour, c);
  //pour a into c
  amount_pour = min(a, cap[2] - c);
  dfs(a - amount_pour, b, c + amount_pour);

  if(b){
    //pour b into a
    amount_pour = min(b, cap[0] - a);
    dfs(a + amount_pour, b - amount_pour, c);
    //pour b into c
    amount_pour = min(b, cap[2] - c);
    dfs(a, b - amount_pour, c + amount_pour);
  }
  if(c){
    //pour c into a
    amount_pour = min(c, cap[0] - a);
    dfs(a + amount_pour, b, c - amount_pour);
    //pour c into b
    amount_pour = min(c, cap[1] - b);
    dfs(a, b + amount_pour, c - amount_pour);
  }
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    fin >> cap[0] >> cap[1] >> cap[2];

    dfs(0, 0, cap[2]);

    sort(end_val.begin(), end_val.end());

    for(int i = 0; i < end_val.size(); i++){
      if(i == 0)
        fout << end_val[i];
      else
        fout << " " << end_val[i];
    }
    fout << endl;
    return 0;
}

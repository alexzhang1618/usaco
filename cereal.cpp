#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> cows;
int sol[100005];
set<int> sat;

void solve(){
  int tot = 0;
  deque<pair<int,int>> curr;
  bool taken[m + 1];
  int prev = 0;
  for(int i = n - 1; i >= 0; i--){
    curr.push_front(cows[i]);
    for(int j = 0; j < m + 1; j++)
      taken[j] = false;
    for(int j = 0; j < curr.size(); j++){
      if(!taken[curr[j].first]){
        tot++;
        taken[curr[j].first] = true;
      }
      else if(!taken[curr[j].second]){
        tot++;
        taken[curr[j].second] = true;
      }
      //cout << curr[i].first << " " << curr[i].second << " " << tot << endl;
    }
    sol[i] = tot;
    if(tot == sat.size()){
      for(int j = 0; j < i; j++)
        sol[j] = tot;
      return;
    }
    prev = tot;
    tot = 0;
  }
}

int main(){
  ifstream fin("cereal.in");
  ofstream fout("cereal.out");
  fin >> n >> m;
  for(int i = 0; i < n; i++){
    int a, b;
    fin >> a >> b;
    cows.push_back({a, b});
    sat.insert(a); sat.insert(b);
  }
  solve();
  for(int i = 0; i < n; i++){
    fout << sol[i] << endl;
  }
  return 0;
}

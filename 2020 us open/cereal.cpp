#include <bits/stdc++.h>
using namespace std;

int n, m, max_n;
vector<pair<int,int>> cows;
int sol[100005];
set<int> sat;
int options[100005];

void solve(){
  int tot = 0;
  bool taken[m + 1];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m + 1; j++)
      taken[j] = false;
    for(int j = i; j < n; j++){
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
    tot = 0;
    options[cows[i].first]--; options[cows[i].second]--;
    if(options[cows[i].first] == 0){
      max_n--;
    }
    if(options[cows[i].second] == 0){
      max_n--;
    }
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
    options[a]++; options[b]++;
  }
  max_n = sat.size();
  solve();
  for(int i = 0; i < n; i++){
    fout << sol[i] << endl;
  }
  return 0;
}

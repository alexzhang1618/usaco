#include <bits/stdc++.h>
using namespace std;

int n;
long long minx, miny, maxx, maxy;
vector<pair<long long, long long>> part;
bool removed[100005];
vector<pair<int, vector<int>>> cows(100005);

long long max(long long a, long long b){
  return a > b ? a : b;
}

long long min(long long a, long long b){
  return a > b ? b : a;
}

bool interact(pair<long long, long long> a, pair<long long, long long> b){
  if(a.first >= b.first && a.second >= b.second)
    return true;
  return b.first >= a.first && b.second >= a.second;
}

int solve(int node, int total){
  if(total == 1)
    return total;
  removed[node] = true;
  int rv = total;
  for(int i = 0; i < n; i++){
    if(!removed[i] && interact(part[i], part[node])){
      removed[i] = true;
      rv = min(solve(i, total - 1), rv);
      removed[i] = false;
    }
  }
  removed[node] = false;
  return rv;
}

int main(){
  ifstream fin("moop.in");
  ofstream fout("moop.out");
  fin >> n;
  for(int i = 0; i < n; i++){
    long long a, b;
    fin >> a >> b;
    if(i == 0){
      minx = a; miny = b;
      maxx = a; maxy = b;
    }
    else{
      minx = min(minx, a); miny = min(miny, b);
      maxx = max(maxx, a); maxy = max(maxy, b);
    }
    part.push_back({a, b});
  }
  sort(part.begin(), part.end());
  if(part[0].first == minx && part[0].second == miny){
    fout << 1 << endl;
    return 0;
  }
  else if(part[n-1].first == maxx && part[n-1].second == maxy){
    fout << 1 << endl;
    return 0;
  }
  if(part[0].second == maxy)
    removed[0] = true;
  if(part[n-1].second == miny)
    removed[n-1] = true;
  int rv = n;
  for(int i = 0; i < n; i++){
    if(rv == 1){
      fout << rv << endl;
      return 0;
    }
    rv = min(solve(i, n), rv);
  }
  fout << rv << endl;
}

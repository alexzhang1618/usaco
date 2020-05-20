/*
ID: alexzha5
TASK: ariprog
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

struct Progression{
  int a, d;
};

int N, M;
vector<int> bisquares;
set<int> unique_bsq;
vector<bool> is_bsq(130000, false);
vector<Progression> progressions;

bool progression_comp(Progression a, Progression b){
  if(a.d < b.d)
    return true;
  if(b.d < a.d)
    return false;
  return a.a < b.a;
}

void dfs(int a, int d){
  int counts = 1;
  int current = a;
  while(counts < N && current + d <= 125000 && is_bsq[current + d]){ // must be a bisquare and not out of range
    current += d;
    counts++;
  }
  if(counts == N){
    Progression p;
    p.a = a;
    p.d = d;
    progressions.push_back(p);
  }
}

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    fin >> N >> M;
    for(int i = 0; i <= M; i++){
      for(int j = i; j <= M; j++){
        int prod = i*i + j*j;
        unique_bsq.insert(prod);
        is_bsq[prod] = true;
      }
    }
    //add these unique bisquares into the vector
    for(set<int>::iterator i = unique_bsq.begin(); i != unique_bsq.end(); i++){
      bisquares.push_back(*i);
    }
    sort(bisquares.begin(), bisquares.end());

    for(int i = 0; i < bisquares.size(); i++){
      for(int j = i + 1; j < bisquares.size(); j++){
        int a = bisquares[i];
        int d = bisquares[j] - bisquares[i]; // the difference to make 2 bisquares
        search(a, d);
      }
    }
    sort(progressions.begin(), progressions.end(), progression_comp);
    if(progressions.size() == 0)
      fout << "NONE" << endl;
    else{
      for(int i = 0; i < progressions.size(); i++){
        //fout << progressions.size() << is_bsq[4] << endl;
        fout << progressions[i].a << " " << progressions[i].d << endl;
      }
    }
    return 0;
}

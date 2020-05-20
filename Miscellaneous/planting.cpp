#include <bits/stdc++.h>
using namespace std;

int N;
int d[100000];

int main(){
  ifstream cin("planting.in");
  ofstream cout("planting.out");
  cin >> N;
  for(int i = 0; i < N - 1; i++){
    int a, b; cin >> a >> b;
    d[a - 1] ++; d[b - 1] ++;
  }
  int D = 0;
  for(int i = 0; i < N; i++){
    if(d[i] > D)
      D = d[i];
  }
  cout << D + 1 << endl;
  return 0;
}

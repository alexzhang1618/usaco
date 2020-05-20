#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int t[MAX];
int N, M, C;

bool pos(int max){
  int wagons = 1;
  int firstArrival = t[0];
  int firstIndex = 0;
  for(int i = 1; i < N; i++){
    if(t[i] - firstArrival > max || i + 1 - firstIndex > C){
      wagons++;
      firstArrival = t[i];
      firstIndex = i;
    }
  }
  return wagons <= M;
}

int binSearch(int low, int high){
  if(low == high) return low;
  else if(low + 1 == high){
    if(pos(low))
      return low;
    return high;
  }
  int mid = (low + high) / 2;
  if(pos(mid)){
    return binSearch(low, mid);
  }
  return binSearch(mid + 1, high);
}

int main(){
  ifstream cin("convention.in");
  ofstream cout("convention.out");
  cin >> N >> M >> C;
  for(int i = 0; i < N; i++)
    cin >> t[i];
  sort(t, t + N);
  cout << binSearch(0, 1000000000) << endl;
}

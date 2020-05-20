#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;

void flip(int left, int right){
  for(int i = left; i < right; i++){
    if(B[i] == 0) B[i] = 1;
    else B[i] = 0;
  }
}

int solve(){
  if(A == B)
    return 0;
  int left = 0, right = N - 1;
  int moves = 0;
  while(left != right){
    for(int i = left; i < N; i++)
      if(A[i] != B[i]){left = i; break;}
    for(int i = left; i < N; i++)
      if(A[i] == B[i]){right = i; break;}
    if(left == N - 1 || left == right)
      return moves;
    flip(left,right);
    moves++;
  }
  return moves;
}

int main(){
  ifstream cin("breedflip.in");
  ofstream cout("breedflip.out");
  cin >> N;
  string s1, s2;
  cin >> s1;
  for(int i = 0; i < N; i++){
    if(s1[i] == 'H') A.push_back(0);
    else A.push_back(1);
  }
  cin >> s2;
  for(int i = 0; i < N; i++){
    if(s2[i] == 'H') B.push_back(0);
    else B.push_back(1);
  }
  cout << solve() << endl;
}

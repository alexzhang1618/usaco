#include <bits/stdc++.h>
using namespace std;

int N, K;
int a1, a2;
int b1, b2;
vector<int> cows;

void swap(int l, int r){
  l--; r--;
  while(l < r){
    int storage = cows[l];
    cows[l] = cows[r];
    cows[r] = storage;
    l++;
    r--;
  }
}
int main(){
  ifstream cin("swap.in");
  ofstream cout("swap.out");
  cin >> N >> K;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  for(int i = 1; i <= N; i++)
    cows.push_back(i);
  for(int i = 0; i < K % 4; i++){
    swap(a1, a2);
    swap(b1, b2);
  }
  for(int i = 0; i < N; i++)
    cout << cows[i] << endl;
}

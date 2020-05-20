#include <bits/stdc++.h>
using namespace std;

int K, N, X;

pair<int,int> cap(){
  int low = 0, high = 100000;
  while(low != high){
    if(low + 1 == high){
      if(low * (low + 1) / 2 >= K)
        return {low, low};
      return {high, high};
    }
    int mid = (low + high) / 2;
    if(mid * (mid + 1) / 2 > K){
      high = mid;
    }
    low = mid + 1;
  }
  return {low, low};
}

int min_time(int dist, int speed, int time){
  if(dist >= K){
    if(speed <= X)
      return time;
    return -1;
  }
  int up = min_time(dist + (speed + 1), speed + 1, time + 1);
  if(up != -1)
    return up;
  int stay = min_time(dist + speed, speed, time + 1);
  if(stay != -1)
    return stay;
  if(speed > X)
    return min_time(dist + (speed - 1), speed - 1, time + 1);
}

int main(){
  ifstream cin("race.in");
  ofstream cout("race.out");
  cin >> K >> N;
  pair<int,int> max = cap();
  for(int i = 0; i < N; i++){
    cin >> X;
    if(X >= max.first)
      cout << max.second << endl;
    else
      cout << min_time(X*(X+1)/2, X, X) << endl;
  }
  return 0;
}

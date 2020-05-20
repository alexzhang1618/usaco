#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<long long, long long>> intervals;

bool validate(int d){
  int prev = intervals[0].first, i = 0;
  int total = n - 1;
  while(total != 0){
    if(i >= m)
      return false;
    if(intervals[i].first - d <= prev && intervals[i].second - d >= prev){
      prev = prev + d;
      total--;
    }
    else if(intervals[i].first - prev >= d){
      prev = intervals[i].first;
      total--;
    }
    else if(intervals[i].second - prev >= d){
      prev = intervals[i].second;
      total--;
      i++;
    }
    else{
      i++;
    }
  }
  return true;
}

int main(){
  ifstream fin("socdist.in");
  ofstream fout("socdist.out");
  fin >> n >> m;
  long long a, b;
  for(int i = 0; i < m; i++){
    fin >> a >> b;
    intervals.push_back({a, b});
  }
  sort(intervals.begin(), intervals.end());

  int low = 1, high = intervals[m-1].second;
  while(low != high){
    if(high - low == 1){
      if(validate(high)){
        fout << high << endl;
        return 0;
      }
      fout << low << endl;
      return 0;
    }
    int mid = (low + high) / 2;
    //cout << mid << validate(mid) << endl;
    if(validate(mid)){
      low = mid;
    }
    else{
      high = mid - 1;
    }
  }
  fout << low << endl;
  return 0;
}

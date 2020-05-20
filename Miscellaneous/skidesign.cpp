/*
ID: alexzha5
TASK: skidesign
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
int N;

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    fin >> N;
    vector<int> hills(N);
    for(int i = 0; i < N; i++){
      fin >> hills[i];
    }
    sort(hills.begin(), hills.end());
    int min_cost = 100000000000000;
    for(int i = 0; i <= hills[N - 1] - 17; i++){
      int cost = 0, count;
      for(int j = 0; j < N; j++){
        if(hills[j] < i){
          count = i - hills[j];
        } else if (hills[j] > i + 17){
          count = hills[j] - i - 17;
        } else {
          count = 0;
        }
        cost += count * count;
      }
      min_cost = min(min_cost, cost);
    }
    fout << min_cost << endl;
    return 0;
}

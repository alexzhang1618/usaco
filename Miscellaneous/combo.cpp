/*
ID: alexzha5
TASK: combo
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> primary, second;

bool close(int a, int b){
  if(abs(a - b) <= 2)
    return true;
  if(abs(a - b) >= N - 2)
    return true;
  return false;
}

bool closeCombo(int x, int y, int z, vector<int> comb){
  return close(x, comb[0]) && close(y, comb[1]) && close(z, comb[2]);
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    fin >> N;
    int storage;
    for(int i = 0; i < 3; i++){
      fin >> storage;
      primary.push_back(storage);
    }
    for(int i = 0; i < 3; i++){
      fin >> storage;
      second.push_back(storage);
    }

    int total = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        for(int k = 1; k <= N; k++){
          if(closeCombo(i, j, k, primary) || closeCombo(i, j, k, second))
            total++;
        }
      }
    }

    fout << total << endl;
    return 0;
}

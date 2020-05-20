/*
ID: alexzha5
TASK: beads
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n;
string necklace;

char find_color(int pos, bool left){
  int inc = left? -1: 1;
  while(necklace[pos] == 'w')
    pos = (pos + inc + n) % n;
  return necklace[pos];
}

int calculate(int pos, bool left){
  int inc = left?-1:1;
  pos = left?pos:pos+1;
  char color = find_color(pos, left);
  int count = 0;
  while(necklace[pos] == 'w' || necklace[pos] == color){
    pos = (pos + inc + n) % n;
    count++;
  }
  return count;
}

int total(int pos){
  return calculate(pos, true) + calculate(pos, false);
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    char curr_bead;
    fin >> n >> necklace;

    //base case
    int i;
    for(i = 0; i < n; i++){
      if(necklace[i] != necklace[0])
        break;
    }
    if(i == n){
      fout << n << endl;
      return 0;
    }

    int max = 0, curr = 0;
    for(i = 0; i < n; i++){
      curr = total(i);
      max = curr>max?curr:max;
    }

    fout << max << endl;
    return 0;
}

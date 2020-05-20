/*
ID: alexzha5
TASK: palsquare
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

map<int, int> squares;
int base;

int base_change(int num, int base){
  if(base == 10)
    return num;
  int digit = 1, ret = 0, b = base;
  for(; num != 0; digit *= 10){
    ret += (num % base) * digit;
    num /= base;
  }
  return ret;
}

bool is_pal(int b){
  //reverse b
  int rev, copy = b;
  for(; b != 0; b /= 10){
    rev += rev * 10 + b % 10;
  }
  return copy == rev;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    fin >> base;
    int b;
    for(int i = 1; i <= 300; i++)
      squares[i] = i * i;

    for(int i = 1; i <= 300; i++){
      b = base_change(squares[i], base);
      if(is_pal(b)){
        fout << base_change(i, base) << " " << b << endl;
      }
    }
    return 0;
}

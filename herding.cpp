#include <bits/stdc++.h>
using namespace std;

int A, B, C;

bool isConsecutive(int a, int b, int c){
  return max(max(a, b), c) - min(min(a, b), c)  == 2 && a + b + c - max(max(a, b), c) - 2 * min(min(a, b), c) == 1;
}

int main(){
  ifstream cin("herding.in");
  ofstream cout("herding.out");
  cin >> A >> B >> C;

  if(A > B) swap(A, B);
  if(B > C) swap(C, B);
  if(A > B) swap(A, B);

  if(C == A + 2)
    cout << 0 << endl;
  else if(C == B + 2 || B == A + 2)
    cout << 1 << endl;
  else
    cout << 2 << endl;
  cout << max(B - A, C - B) - 1 << endl;
}

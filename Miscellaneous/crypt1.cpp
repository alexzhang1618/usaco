/*
ID: alexzha5
TASK: crypt1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;

bool isDigit(int a, bool isPartial){
  if(isPartial && (a >= 1000 || a < 100))
    return false;
  for(; a != 0; a /= 10){
    if(find(nums.begin(), nums.end(), a % 10) == nums.end())
      return false;
  }
  return true;
}

bool isCrypt(int a, int b){
  return isDigit(a * (b % 10), true) && isDigit(a * (b / 10), true) && isDigit(a * b, false);
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    fin >> N;

    int storage, total = 0;
    for(int i = 0; i < N; i++){
      fin >> storage;
      nums.push_back(storage);
    }

    // construct numbers
    int num1, num2;
    for(int h = 0; h < N; h++){
      num1 = nums[h];
      for(int t1 = 0; t1 < N; t1++){
        num1 = num1 * 10 + nums[t1];
        for(int o1 = 0; o1 < N; o1++){
          num1 = num1 * 10 + nums[o1];
          for(int t2 = 0; t2 < N; t2++){
            num2 = nums[t2];
            for(int o2 = 0; o2 < N; o2++){
              num2 = num2 * 10 + nums[o2];
              if(isCrypt(num1, num2))
                total++;
              num2 /= 10;
            }
            num2 /= 10;
          }
          num1 /= 10;
        }
        num1 /= 10;
      }
      num1 /= 10;
    }

    fout << total << endl;
    return 0;
}

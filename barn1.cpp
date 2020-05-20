/*
ID: alexzha5
TASK: barn1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b){
  return a > b;
}

vector<int> saved(vector<int> stall_nums){
  vector<int> ret;
  for(int i = 1; i < stall_nums.size(); i++){
    ret.push_back(stall_nums[i] - stall_nums[i - 1] - 1);
  }
  sort(ret.begin(), ret.end(), comp);
  return ret;
}

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int max_boards, stalls, num_cows, stalls_covered;
    fin >> max_boards >> stalls >> num_cows;

    vector<int> stall_nums(num_cows);
    for(int i = 0; i < num_cows; i++){
      fin >> stall_nums[i];
    }
    sort(stall_nums.begin(), stall_nums.end());
    stalls_covered = stall_nums[stall_nums.size() - 1] - stall_nums[0] + 1; // number of stalls covered with only 1 board
    vector<int> stalls_saved = saved(stall_nums);

    while(max_boards != 1 && stalls_covered != num_cows){
      stalls_covered -= stalls_saved[0];
      stalls_saved.erase(stalls_saved.begin()); // erase greatest save
      max_boards -= 1;
    }

    fout << stalls_covered << endl;
    return 0;
}

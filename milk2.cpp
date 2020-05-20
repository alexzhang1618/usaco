/*
ID: alexzha5
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Time{
  int start;
  int end;
  Time() {}
  Time(int s, int e) : start(s), end(e) {}
};

int n;

int time_comp(const void *time1, const void *time2){
  return ((Time*)time1)->start - ((Time*)time2)->start;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin >> n;
    Time schedule [n];
    int time_milk, time_no_milk;

    for(int i = 0; i < n; i++){
      fin >> schedule[i].start >> schedule[i].end;
    }
    qsort(schedule, n, sizeof(Time), time_comp);

    //rebuild pairs
    time_milk = 0;
    time_no_milk = 0;
    int cur = 0;

    for(int i = 0; i < n; i++){
      if(schedule[i].start > schedule[cur].end){ // time without milking
        time_no_milk = max(time_no_milk, schedule[i].start - schedule[cur].end);
        time_milk = max(time_milk, schedule[cur].end - schedule[cur].start);
        cur = i;
      } else {
        schedule[cur].end = max(schedule[cur].end, schedule[i].end);
      }
    }

    fout << max(time_milk, schedule[cur].end - schedule[cur].start) << " " << time_no_milk << endl;
    return 0;
}

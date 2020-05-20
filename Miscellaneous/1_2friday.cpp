/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: alexzha5
TASK: friday
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int years, day = 2; // day starts on monday
    fin >> years;
    int days [7] = {0, 0, 0, 0, 0, 0, 0}; // sat, sun, mon, tues, wed, thurs, fri
    int month [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days of each month
    while (years != 0){
      for(int i = 0; i < 12; i++){
        day += 12;
        days[day % 7]++;
        day += month[i] - 13;
        if(i == 1 && (years - 1) % 4 == 0)
          day += 1;
      }
      years--;
    }
    for(int i = 0; i < 12; i++)
      fout << days[i] << " ";
    fout << endl;
    return 0;
}

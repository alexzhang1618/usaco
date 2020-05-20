/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: alexzha5
TASK: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    int a1 = 1, b1 = 1;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    fin >> a >> b;
    for(int i = 0; i < a.size(); i++)
      a1 *= alpha.find(a[i]) + 1;
    for(int i = 0; i < b.size(); i++)
      b1 *= alpha.find(b[i]) + 1;
    if(a1 % 47 == b1 % 47)
      fout << "GO" << endl;
    else
      fout << "STAY" << endl;
    return 0;
}

/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: alexzha5
TASK: whereami
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    int n;
    string char;
    fin >> n >> char;

    fout << endl;
    return 0;
}

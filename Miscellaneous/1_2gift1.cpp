/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: alexzha5
TASK: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np, totalMoney, numRecievers, moneyRecieved;
    string giver, reciever;
    fin >> np;

    //initialize arrays
    string names [np];
    int balance [np];

    for(int i = 0; i < np; i++){
      fin >> names[i];
      balance[i] = 0;
    }

    //calculate balances
    for(int i = 0; i < np; i++){
      fin >> giver;
      fin >> totalMoney;
      fin >> numRecievers;

      //subtract balance from giver
      for(int j = 0; j < np; j++)
        if(giver == names[j]){
          if(numRecievers != 0){
            balance[j] -= totalMoney;
            balance[j] += totalMoney % numRecievers;
          }
        }

      //add balance to reciever
      for(int j = 0; j < numRecievers; j++){
        fin >> reciever;
        for(int k = 0; k < np; k++){
          if(reciever == names[k])
            balance[k] += totalMoney / numRecievers;
        }
      }
    }

    //print balances
    for(int i = 0; i < np; i++)
      fout << names[i] << " " << balance[i] << endl;

    return 0;
}

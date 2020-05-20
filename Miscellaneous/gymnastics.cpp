/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: alexzha5
TASK: gymnastics
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int search(int a[], int b, int size){
  for(int i = 0; i < size; i++){
    if (a[i] == b)
      return i;
  }
}

int main() {
    ofstream fout ("gymnastics.out");
    ifstream fin ("gymnastics.in");
    int k, n;
    int count = 0;
    int rank [n];
    std::map<tuple, std::boolean> greater;
    std::map<tuple, std::boolean> less;
    fin >> k >> n;
    for(int i = 0; i < k; i++){
      // fill current row
      for(int j = 0; j < n; j++){
        fin >> rank[j];
      }
      // input data for pairs
      if(i == 0){
        for(int k = 1; k <= n; k++){
          for(int j = k + 1; j <= n; j++){
            if(search(rank, k, rank.size()) < search(rank, j, rank.size())){
              greater[(k, j)] = true;
              less[(k, j)] = false;
            }else{
              greater[(k, j)] = false;
              less[(k, j)] = true;
            }
          }
        }
      }else{
        for(int k = 1; k <= n; k++){
          for(int j = k + 1; j <= n; j++){
            if(search(rank, k, rank.size()) < search(rank, j, rank.size())){
              greater[(k, j)] &= true;
              less[(k, j)] &= false;
            }else{
              greater[(k, j)] &= false;
              less[(k, j)] &= true;
      }
    }
    for(auto&x : greater){
      if(x.second)
        count++;
    }
    for(auto&x : less){
      if(x.second)
        count++;
    }
    fout << count << endl;
    return 0;
}

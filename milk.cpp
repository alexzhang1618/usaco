/*
ID: alexzha5
TASK: milk
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

struct farmer{
  int price;
  int units;
  farmer() {}
  farmer(int p, int u) : price(p), units(u) {}
};

bool price_comp(farmer f1, farmer f2){
  return f1.price < f2.price;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int units, n, price = 0;
    fin >> units >> n;
    vector<farmer> farmers(n);

    for(int i = 0; i < n; i++){
      fin >> farmers[i].price >> farmers[i].units;
    }

    sort(farmers.begin(), farmers.end(), price_comp);

    while(units != 0){
      for(int i = 0; i < n; i++){
        if(farmers[i].units > units){
          price += farmers[i].price * units;
          units -= units;
        } else {
          price += farmers[i].price * farmers[i].units;
          units -= farmers[i].units;
        }
      }
    }

    fout << price << endl;
    return 0;
}

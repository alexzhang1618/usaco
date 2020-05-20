/*
ID: alexzha5
TASK: transform
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int n;

bool is_eq(vector<vector<char>> a, vector<vector<char>> b){
  bool rv = true;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      rv = rv && a[i][j] == b[i][j];
  return rv;
}

vector<vector<char>> rotate90(vector<vector<char>> a)
{
    vector<vector<char>> copy(a);
    // Traverse each cycle
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {

            // Swap elements of each cycle
            // in clockwise direction
            int temp = copy[i][j];
            copy[i][j] = copy[n - 1 - j][i];
            copy[n - 1 - j][i] = copy[n - 1 - i][n - 1 - j];
            copy[n - 1 - i][n - 1 - j] = copy[j][n - 1 - i];
            copy[j][n - 1 - i] = temp;
        }
    }
    return copy;
}

vector<vector<char>> rotate180(vector<vector<char>> a){
  vector<vector<char>> copy(a);
  return rotate90(rotate90(a));
}

vector<vector<char>> rotate270(vector<vector<char>> a){
  vector<vector<char>> copy(a);
  return rotate90(rotate90(rotate90(a)));
}

vector<vector<char>> reflect(vector<vector<char>> a){
  vector<vector<char>> copy(a);
  char storage;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n / 2; j++){
      storage = copy[i][j];
      copy[i][j] = copy[i][n - j - 1];
      copy[i][n - j - 1] = storage;
    }
  }
  return copy;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    fin >> n;
    vector<vector<char>> original(n, vector<char>(n));
    vector<vector<char>> changed(n, vector<char>(n));

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        fin >> original[i][j];
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        fin >> changed[i][j];
      }
    }


    //CASE 1: 90 DEGREES CLOCKWISE
    if(is_eq(rotate90(original), changed)){
      fout << 1 << endl;
      return 0;
    }

    //CASE 2: 180 DEGREES
    if(is_eq(rotate180(original), changed)){
      fout << 2 << endl;
      return 0;
    }

    //CASE 3: 270 DEGREES
    if(is_eq(rotate270(original), changed)){
      fout << 3 << endl;
      return 0;
    }

    //CASE 4: REFLECT
    if(is_eq(reflect(original), changed)){
      fout << 4 << endl;
      return 0;
    }

    //CASE 5: COMBINATION
    if(is_eq(rotate90(reflect(original)), changed) || is_eq(rotate180(reflect(original)), changed) || is_eq(rotate270(reflect(original)), changed)){
      fout << 5 << endl;
      return 0;
    }

    //CASE 6: NO CHANGE
    if(is_eq(original, changed)){
      fout << 6 << endl;
      return 0;
    }

    fout << 7 << endl;
    return 0;
}

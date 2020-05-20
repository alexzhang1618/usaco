#include <bits/stdc++.h>
using namespace std;

int N, K;
int line_size[105];
string sentence[105];

int main(){
  ifstream cin("word.in");
  ofstream cout("word.out");
  cin >> N >> K;
  int curr_line = 0;
  for(int i = 0; i < N; i++){
    string word;
    cin >> word;
    if(line_size[curr_line] + word.size() <= K){
      if(line_size[curr_line] == 0)
        sentence[curr_line] += word;
      else
        sentence[curr_line] += " " + word;
      line_size[curr_line] += word.size();
    }
    else{
      sentence[curr_line] += "\n";
      curr_line++;
      sentence[curr_line] += word;
      line_size[curr_line] += word.size();
    }
  }
  for(int i = 0; i <= curr_line; i++){
    cout << sentence[i];
  }
  cout << endl;
  return 0;
}

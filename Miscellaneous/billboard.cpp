#include <bits/stdc++.h>
using namespace std;

int cornersCovered = 0;
void covered(int x, int y, int x1, int y1, int x2, int y2){
  if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
    cornersCovered++;
}

int main(){
  ifstream cin("billboard.in");
  ofstream cout("billboard.out");
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  covered(x1, y1, x3, y3, x4, y4);
  covered(x2, y1, x3, y3, x4, y4);
  covered(x1, y2, x3, y3, x4, y4);
  covered(x2, y2, x3, y3, x4, y4);
  if(cornersCovered < 2){
    cout << abs((x2 - x1) * (y2 - y1)) << endl;
  }
  else if(cornersCovered == 4){
    cout << 0 << endl;
  }
  else { 
    int xL = max(x1, x3);
    int xR = min(x2, x4);
    int yL = max(y1, y3);
    int yR = min(y2, y4);
    cout << abs((x2 - x1) * (y2 - y1)) - abs((xR - xL) * (yL - yR)) << endl;
  }
  return 0;
}

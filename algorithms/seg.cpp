#include <bits/stdc++.h>

using namespace std;

int n;
int seg[400000];

//Segment Trees

//Prefix Sum - sum representing the sums of the numbers of the nodes
//insert + finding sum both in log n time
//used for querys or where the total array is very big

//segment tree represented as an array, where 2n+1 and 2n+2 are
//the child nodes of the parent node n

void insert(int curr, int start, int end, int index, int value){
  if(index > end || index < start)
    return;
  if(start == end){
    seg[curr] = value;
    return;
  }
  //recurse down the segment tree
  insert(2*curr+1, start, (start+end)/2, index, value);
  insert(2*curr+2, (start+end)/2, end, index, value);
  seg[curr] = seg[2*curr+1] + seg[2*curr+2];
}
void insert(int index, int value){
  return insert(0, 0, n - 1, index, value);
}

int sum(int curr, int start, int end, int ql, int qr){
  if(ql > end || qr < start)
    return 0;
  if(start >= ql && end <= qr)
    return seg[curr];
  return sum(2*curr+1, start, (start+end)/2, ql, qr) + sum(2*curr+2,
        (start+end)/2, end, ql, qr);
}
int sum(int ql, int qr){
  return sum(0, 0, n-1, ql, qr);

}
int main(){
  cin >> n;
  while(true){
    int x;
    cin >> x;
    if(x == 1){ // query to insert
      int ind, val;
      cin >> ind >> val;
      insert(ind, val);
    }
    else{
      int ql, qr;
      cin >> ql >> qr;
      cout << sum(ql, qr) << endl;
    }
  }
}
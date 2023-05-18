#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321
int n;
int in[100'003];
int post[100'003];
int idx[100'003];


void recur(int inSt, int inEn, int postSt, int postEn){
  if(inSt > inEn || postSt > postEn) return;

  int rootIdx = idx[post[postEn]];
  int leftSz = rootIdx - inSt;
  int rightSz = inEn - rootIdx;

  cout << in[rootIdx] << ' ';


  recur(inSt, rootIdx-1, postSt, postSt + leftSz -1);
  recur(rootIdx+1, inEn, postSt + leftSz, postEn-1);


}



int main(){

  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> in[i];
    idx[in[i]] = i;
  }
  for(int i=1; i<=n; i++) cin >> post[i];

  recur(1, n, 1, n);
}
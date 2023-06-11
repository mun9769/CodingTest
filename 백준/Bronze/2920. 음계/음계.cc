#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
#define ii pair<int, int>
#define INF 987654321


vector<int> v;


int main(){
  for(int i=0; i<8; i++){
    int a; cin >> a;
    v.push_back(a);
  }
  bool possible = true;

  for(int i=0; i<8; i++){
    if(v[i] != i+1) {
      possible = false;
      break;
    }
  }
  if(possible){ cout << "ascending"; return 0;}

  possible = true;

  for(int i=0; i<8; i++){
    if(v[i] != 8-i){
      possible = false;
      break;
    }
  }
  if(possible) { cout << "descending"; return 0;}
  
  cout << "mixed";
}
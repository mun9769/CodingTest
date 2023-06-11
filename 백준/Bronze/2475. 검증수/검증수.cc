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
  int sum=0;
  for(int i=0; i<5; i++){
    int a; cin >> a;
    sum += a*a;
  }
  cout << sum % 10;
}
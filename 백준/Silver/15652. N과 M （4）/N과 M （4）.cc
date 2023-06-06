#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[22];

void dfs(int num, int target){
  if(target == m+1){ 
    for(int i=1; i<=m; i++) cout << arr[i] << ' ';
    cout << endl;
    return;
  }

  for(int i = num; i<=n; i++){
    arr[target] = i;
    dfs(i, target+1);
  }
}

int main(){
  cin.tie(0)->ios_base::sync_with_stdio(0);
  cin >> n >> m;
  dfs(1, 1);
}
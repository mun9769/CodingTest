#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>

#define MAX 987987987
int n, k;

int dist[11][11];
bool vis[11];

int main() {
  cin >> n >> k;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>> dist[i][j];
    }
  }

  for(int z=0; z<n; z++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        dist[i][j] = min(dist[i][j], dist[i][z] + dist[z][j]);

  vector<int> arr;
  for(int i=0; i<n; i++) arr.push_back(i);

  int ans = INT32_MAX;

  do {
    if(arr[0] != k) continue;

    int tmp = 0;

    for(int i=1; i<n; i++){
      tmp += dist[arr[i-1]][arr[i]];
    }
    ans = min(ans, tmp);
  }while(next_permutation(arr.begin(), arr.end()));

  cout<< ans;



  
}

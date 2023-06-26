

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <numeric>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
#define ll long long
using namespace std;


vector<string> v;
int k;
int sz[50][2];

int main() {
    init
    sz[0][0] = 1;
    sz[0][1] = 0;
    
    for(int i=0; i<46; i++){
        sz[i+1][1] += sz[i][0];
        
        sz[i+1][0] += sz[i][1];
        sz[i+1][1] += sz[i][1];
    }
    cin >> k;
    cout << sz[k][0] << ' ' << sz[k][1];
}

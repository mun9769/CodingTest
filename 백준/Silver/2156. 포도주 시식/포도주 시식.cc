

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


int ts;
int n;

int wine[10'005];

int total[3][10'005];

int main() {
    init
    cin >> n;
    for(int i=0; i<n; i++) cin >> wine[i];
    
    total[0][0] = 0;
    total[1][0] = wine[0];
    total[2][0] = -INF;
    
    for(int i=1; i<n; i++){
        int prv = i-1;
        total[0][i] = max(max(total[0][prv], total[1][prv]), total[2][prv]);
        
        total[1][i] = total[0][prv] + wine[i];
        
        total[2][i] = total[1][prv] + wine[i];
    }
    
    int ans = 0;
    for(int k = 0; k<3; k++) ans = max(ans, total[k][n-1]);
    cout << ans;
    
    
}

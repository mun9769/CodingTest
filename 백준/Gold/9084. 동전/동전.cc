

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
int n, m;

int dp[10'004];

int main() {
    init;
    cin >> ts;
    while(ts-- > 0){
        vector<int> coins;
        cin >> n;
        for(int i=1; i<=n; i++) { int a; cin >> a; coins.push_back(a); }
        sort(coins.begin(), coins.end());
        cin >> m;
        fill(dp, dp+m+1, 0);
        dp[0] = 1;
        for(auto coin: coins){
            for(int i=coin; i<=m; i++){
                dp[i] += dp[i-coin];
            }
        }
        
        cout << dp[m] << ' ';
        
    }

    
}

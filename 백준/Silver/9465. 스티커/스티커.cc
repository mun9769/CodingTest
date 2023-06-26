

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
int dp[2][2][100'005];

int sticker[2][100'005];

int main() {
    init
    cin >> ts;
    while(ts-->0){
        cin >> n;
        
        for(int i=1; i<=n; i++){ cin >> sticker[0][i]; }
        for(int i=1; i<=n; i++){ cin >> sticker[1][i]; }
        
        dp[1][0][1] = sticker[0][1];
        dp[1][1][1] = sticker[1][1];
        
        dp[0][0][1] = 0;
        dp[0][1][1] = 0;
        
        for(int j=1; j<n; j++){
            int mx = max(dp[1][0][j], dp[1][1][j]);
            
            dp[0][0][j+1] = mx;
            dp[0][1][j+1] = mx;
            
            
            dp[1][0][j+1] = max(max(dp[1][1][j], dp[0][0][j]), dp[0][1][j]) + sticker[0][j+1];
            dp[1][1][j+1] = max(max(dp[1][0][j], dp[0][0][j]), dp[0][1][j]) + sticker[1][j+1];
        }
        
        /*
        for(int j = 1; j<=n; j++){
            cout << setw(4) << dp[1][0][j] << ' ';
        }
        cout << endl;
        for(int j = 1; j<=n; j++){
            cout << setw(4) << dp[1][1][j] << ' ';
        }
         */
        
        int ans = 0;
        ans = max(dp[1][0][n], dp[1][1][n]);
        cout << ans << '\n';
    }
    
    
}

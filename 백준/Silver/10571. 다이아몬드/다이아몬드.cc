

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
int n, k;

pair<float, float> dia[221];


struct cmp{
    bool operator()(pair<float,float> a,pair<float,float> b){
        return a.second > b.second;
    }
};

int main() {
    init
    cin >> ts;
    
    while(ts-->0){
        cin >> n;
        
        int dp[222] = {0,};
        
        for(int i=1; i<=n; i++){
            cin >> dia[i].first >> dia[i].second;
            dp[i] = 1;
            
            for(int j=1; j<i; j++){
                float wei = dia[j].first;
                float beauty = dia[j].second;
                
                if(wei < dia[i].first and beauty > dia[i].second){
                    
                    dp[i] = max(dp[i], dp[j]+1);
                    
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, dp[i]);
            // cout << dp[i] << ' ';
        }
        cout << ans << ' ';
        
    }
    
    
}

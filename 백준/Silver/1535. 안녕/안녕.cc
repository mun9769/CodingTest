

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

int dam[22];
int happy[22];

int ans;

int main() {
    init;
    cin >> n;
    for(int i=0; i<n; i++) cin >> dam[i];
    for(int i=0; i<n; i++) cin >> happy[i];
    
    for(int i=1; i < (1 << n); i++){
        
        vector<int> v;
        for(int j=0; j<n; j++){
            if(i & (1 << j)) v.push_back(j);
        }
        int totalHappy = 0;
        int totalDam = 0;
        for(int id: v){
            totalDam += dam[id];
            totalHappy += happy[id];
        }
        if(totalDam < 100) {
            ans = max(ans, totalHappy);
        }
        
    }
    cout << ans;

    
}

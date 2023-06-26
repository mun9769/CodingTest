

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
int cnt[100'005];

int main() {
    init
    
    fill(cnt, cnt+100'005, -1);
    
    cnt[2] = 1;
    cnt[5] = 1;
    
    queue<int> q;
    
    q.push(2);
    q.push(5);
    
    while(q.size()){
        
        int here = q.front();
        q.pop();
        
        for(auto there: {here+2, here+5}){
            
            if(there < 100'004 and cnt[there] == -1){
                cnt[there] = cnt[here] + 1;
                q.push(there);
            }
        }
    }
    
    cin >> k;
    cout << cnt[k];
}

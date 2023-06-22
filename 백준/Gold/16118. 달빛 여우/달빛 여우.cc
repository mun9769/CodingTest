//
//  main.cpp
//  cpp
//
//  Created by moon on 2023/06/20.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <tuple>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9
using namespace std;


int n, m;
vector<ii> adj[4040];
int foxDist[4040];
float wolfDist[2][4040];

void FoxDijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 1});
    foxDist[1] = 0;
    
    while(pq.size()){
        auto [d, cur] = pq.top();
        pq.pop();
        
        for(auto [cost, nxt]: adj[cur]){
            if(foxDist[nxt] > foxDist[cur] + cost){
                foxDist[nxt] = foxDist[cur] + cost;
                pq.push({foxDist[nxt], nxt});
            }
        }
    }
}

void WolfDijkstra(){
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push({0, 1, 1});
    wolfDist[0][1] = 0;
    // wolfDist[1][1] = 0;
    
    while(pq.size()){
        auto [d, cur, boost] = pq.top();
        pq.pop();
        
        
        
        int prev_state = (boost == 1) ? 0 : 1;
        if(wolfDist[prev_state][cur] < d) continue;

        for(auto [cost, nxt]: adj[cur]){
            
            if(boost == 1){
                float nDist = wolfDist[0][cur] + (float)cost / 2;
                if(wolfDist[1][nxt] > nDist){
                    wolfDist[1][nxt] = nDist;
                    pq.push({nDist, nxt, 0});
                }
            }
            else {
                float nDist = wolfDist[1][cur] + (float)cost * 2;
                if(wolfDist[0][nxt] > nDist){
                    wolfDist[0][nxt] = nDist;
                    pq.push({nDist, nxt, 1});
                }
            }
        }
    }
    
}


int main() {
    init
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    fill(foxDist, foxDist+4040, INF);
    fill(wolfDist[0], wolfDist[0]+4040, INF);
    fill(wolfDist[1], wolfDist[1]+4040, INF);
    
    FoxDijkstra();
    WolfDijkstra();
    int ans = 0;
    for(int i=2; i<=n; i++){
        float mn = min(wolfDist[0][i], wolfDist[1][i]);
        if((float)foxDist[i] < mn) {
            ans++;
        }
    }
    cout << ans;
    /*
    cout << endl;
    for(int i=1; i<=n; i++){
        cout <<setw(4)<< foxDist[i] << ' ';
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        cout <<setw(4)<< wolfDist[0][i] << ' ';
    }
    cout << endl;
    for(int i=1; i<=n; i++){
        cout <<setw(4) << wolfDist[1][i] << ' ';
    }
     */
    
}

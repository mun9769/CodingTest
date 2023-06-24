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
#include <stack>
#include <tuple>
#include <algorithm>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
using namespace std;



int ts;
int n, m;
bool chk[100'005];
int cnt[100'005];

vector<int> adj[100'005];
vector<int> revAdj[100'005];

vector<vector<int>> scc;
vector<int> s;

stack<int> stk;

void frontDfs(int here){
    chk[here] = true;
    
    for(auto there: adj[here]){
        if(chk[there] == false)
            frontDfs(there);
    }
    
    stk.push(here);
}


void revDfs(int here){
    
    chk[here] = true;
    s.push_back(here);
    
    for(auto there: revAdj[here]){
        if(chk[there] == false)
            revDfs(there);
    }
}

int group[100'002];
int indegree[100'005];



int main() {
    init
    cin >> ts;
    while(ts-->0){
        cin >> n >> m;
        fill(indegree, indegree+n+1, 0);
        int g = 0;
        
        for(int i=0; i<n + 1; i++){
            adj[i].clear();
            revAdj[i].clear();
        }
        scc.clear();
        
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            revAdj[b].push_back(a);
        }
        
        fill(chk, chk+n+1, false);
        
        for(int i=1; i<=n; i++){
            if(chk[i] == false)
                frontDfs(i);
        }
        
        fill(chk, chk+n+1, false);
        
        while(stk.size()){
            int here = stk.top();
            stk.pop();
            if(chk[here]) continue;
            
            s.clear();
            revDfs(here);
            scc.push_back(s);
        }
        
        for(auto component: scc){
            g++;
            for(int obj: component){
                group[obj] = g;
            }
        }
        
        /*
        cout << endl;
        for(auto component: scc){
            for(int obj: component){
                cout << obj << ' ';
            }
            cout << -1 << endl;
        }
         */
        
        
        for(auto component: scc){
            for(int obj: component){
                
                for(auto nxt: adj[obj]){
                    // int groupId = group[nxt];
                    if(group[nxt] == group[obj]) continue;
                    
                    indegree[group[nxt]]++;
                }
                
            }
        }
        int ans = 0;
        for(int i=1; i<=g; i++){
            if(indegree[i] == 0) ans++;
            // cout << indegree[i] << ' ';
        }
        // cout << endl;
        cout << ans << ' ';
    }
}

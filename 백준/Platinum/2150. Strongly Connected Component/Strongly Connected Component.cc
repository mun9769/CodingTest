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
#include <algorithm>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
using namespace std;



int v, e;
vector<int> adj[10'005];
vector<int> backAdj[10'005];

vector<int> doneVertex;
bool chk[10'005];
vector<vector<int>> scces;

vector<int> scc;

void dfs(int here){
    
    chk[here] = true;
    
    
    for(auto there: adj[here]){
        if(chk[there] == false){
            dfs(there);
        }
    }
    doneVertex.push_back(here);
}

void backDfs(int here){
    
    chk[here] = true;
    scc.push_back(here);
    
    for(auto there: backAdj[here]){
        
        if(chk[there] == false){
            backDfs(there);
        }
    }
}

int main() {
    init
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        backAdj[b].push_back(a);
    }
    for(int i=1; i<=v; i++){
        if(chk[i] == false){
            dfs(i);
        }
    }
    
    fill(chk, chk+10'005, false);
    
    for(int i=(int)doneVertex.size()-1; i>=0; i--){
        int here = doneVertex[i];
        if(chk[here] == false){
            scc.clear();
            backDfs(here);
            scces.push_back(scc);
        }
    }
    
    
    for(auto& s: scces){
        sort(s.begin(), s.end());
    }
    
    for(int i=0; i<scces.size(); i++){
        for(int j=i+1; j<scces.size(); j++){
            if(scces[i][0] > scces[j][0]) {
                swap(scces[i], scces[j]);
            }
        }
    }
    
    cout << scces.size() << '\n';
    for(auto s: scces){
        for(int k: s)
            cout << k << ' ';
        cout << -1 << '\n';
    }
   
}

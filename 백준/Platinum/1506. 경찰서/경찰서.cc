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



int n;

int cost[102];
vector<int> adj[102];
vector<int> revAdj[102];

stack<int> stk;

bool chk[102];

vector<vector<int>> scc;
vector<int> component;

void frontDfs(int here){
    
    chk[here] = true;
    
    for(auto there: adj[here]){
        if(chk[there] == false){
            frontDfs(there);
        }
    }
    stk.push(here);
}

void revDfs(int here){
    chk[here] = true;
    component.push_back(here);
    
    for(auto there: revAdj[here]){
        if(chk[there] == false){
            revDfs(there);
        }
    }
}

int main() {
    init
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == '1'){
                adj[i].push_back(j);
                revAdj[j].push_back(i);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(chk[i] == false)
            frontDfs(i);
    }
    fill(chk, chk+102, false);
    int ans = 0;
    
    while(stk.size()){
        int here = stk.top();
        stk.pop();
        if(chk[here] == true) continue;
        
        component.clear();
        revDfs(here);
        int price = INF;
        for(auto city: component){
            price = min(price, cost[city]);
        }
        ans += price;
    }
    cout << ans;
    
    
    
    
}

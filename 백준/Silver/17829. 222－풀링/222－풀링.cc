#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n;
int board[1050][1050];

int dfs(int x, int y, int sz) {
    vector<int> v;
    if(sz == 2) {
        for(int i=x; i<x+2; i++) for(int j=y; j<y+2; j++) v.push_back(board[i][j]);
        sort(v.begin(), v.end());
        return v[2];
    }

    int num;
    num = dfs(x,y,sz/2);
    v.push_back(num);
    num = dfs(x+sz/2,y,sz/2);
    v.push_back(num);
    num = dfs(x,y+sz/2,sz/2);
    v.push_back(num);
    num = dfs(x+sz/2,y+sz/2,sz/2);
    v.push_back(num);
    sort(v.begin(), v.end());

    return v[2];
}


int main() {
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> board[i][j];

    cout << dfs(0, 0, n);
}

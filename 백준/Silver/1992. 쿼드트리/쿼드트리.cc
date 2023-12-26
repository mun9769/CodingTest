#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n;
string str;
vector<string> img;

string dfs(int x, int y, int sz) {
    string result;
    bool all_zero = true;
    bool all_bit = true;
    for(int i=x; i<x + sz; i++) for(int j=y; j<y + sz; j++) {
        if(img[i][j] == '0') all_bit = false;
        else all_zero = false;
    }

    if(all_zero) { return "0"; }
    if(all_bit) { return "1"; }

    return "(" + dfs(x, y, sz/2) + dfs(x, y+sz/2, sz/2) + dfs(x+sz/2, y, sz/2) + dfs(x+sz/2, y+sz/2, sz/2) + ")";
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        img.push_back(str);
    }
    cout << dfs(0,0,n);
}

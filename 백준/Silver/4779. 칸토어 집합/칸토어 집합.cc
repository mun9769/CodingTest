#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n;

void dfs(int st, int en) {
    int gap = en - st;
    if(gap == 1) {
        cout << '-';
        return;
    }

    dfs(st, st + gap/3);

    for(int i=0; i< gap/3; i++) cout << ' ';

    dfs(st + gap*2/3, en);
}

int main() {
    while(cin >> n) {
        dfs(0, pow(3, n));
        cout << '\n';
    }
}

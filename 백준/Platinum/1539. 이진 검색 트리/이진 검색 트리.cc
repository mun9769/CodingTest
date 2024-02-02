#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;

int n;
set<int> s;
int x;
ll ans;
ll dep[250'006];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    cin >> x;
    s.insert(x);
    dep[x] = 1;

    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        auto rht = s.lower_bound(x);
        auto lft = (rht != s.begin()) ? prev(rht) : s.begin();

        if (rht == s.end()) {
            int p = *lft;
            dep[x] = dep[p] + 1;
        }
        else {
            int lftp = *lft;
            int rhtp = *rht;
            int p = (dep[lftp] > dep[rhtp]) ? lftp : rhtp;
            dep[x] = dep[p] + 1;
        }
        s.insert(x);


    }
	ans = accumulate(dep, dep + n, 0LL);
    cout << ans;

    return 0;
}

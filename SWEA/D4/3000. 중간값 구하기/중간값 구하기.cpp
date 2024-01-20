#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using ll = long long;
using pll = pair<long long, long long>;
#define inf 987654321
#define Mxn 1'001

int T;
int n, a, b;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        cout <<'#'<<tc<<' ';

        multiset<int> lft, rht;
        ll answer = 0;
        cin >> n >> a;
        lft.insert(a);

        for(int i=0; i<n; i++) {
            cin >> a >> b;
            lft.insert(a);
            lft.insert(b);

            auto iter = lft.end();
            --iter; rht.insert(*iter);
            --iter; rht.insert(*iter);
            iter = --lft.end(); lft.erase(iter);
            iter = --lft.end(); lft.erase(iter);

            iter = rht.begin();
            lft.insert(*iter);
            rht.erase(iter);

            iter = --lft.end();
            answer += *iter;
        }

        cout << answer % 20171109 << '\n';

    }
}
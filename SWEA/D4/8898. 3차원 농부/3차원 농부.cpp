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
int n, m;
ll c1, c2;
int num;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        cout <<'#'<<tc<<' ';
        vector<int> cow;
        vector<int> horse;

        cin >> n >> m;
        cin >> c1 >> c2;
        for(int i=0; i<n; i++) cin >> num, cow.push_back(num);
        for(int i=0; i<m; i++) cin >> num, horse.push_back(num);

        int mnDist = INT32_MAX;
        ll answer = 0;
        sort(horse.begin(), horse.end());

        for(auto x: cow) {
            auto lb = lower_bound(horse.begin(), horse.end(), x);
            auto prv = (lb == horse.begin()) ? horse.begin() : prev(lb);
            if(lb == horse.end()) lb--;


            if(*lb == x) {
                if(mnDist == 0)
                    answer += 1;
                else
                    mnDist = 0, answer = 1;
            }
            else {
                int rht = abs(x - *lb);
                int lft = abs(x - *prv);

                if(mnDist < min(lft, rht))
                    continue;

                if(rht < lft) {
                    if(mnDist == rht)
                        answer += 1;
                    else
                        mnDist = rht, answer = 1;
                }
                else if(lft < rht) {
                    if(mnDist == lft)
                        answer += 1;
                    else
                        mnDist = lft, answer = 1;
                }
                else if(lft == rht) {
                    if(prv == lb) {
                        if(mnDist == lft)
                            answer += 1;
                        else
                            mnDist = lft, answer = 1;
                    }
                    else {
                        if(mnDist == lft)
                            answer += 2;
                        else
                            mnDist = lft, answer = 2;
                    }
                }

            }
        }
        cout << abs(c1 - c2) + mnDist << ' ' << answer << '\n';
    }
}
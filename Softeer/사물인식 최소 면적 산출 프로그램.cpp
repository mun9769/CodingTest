#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

vector<ii> point[22];
int N, K;
int ans = INT32_MAX;

void dfs(int cur, int l, int r, int t, int b) {
    if(cur == K+1) {
        int area = (r-l) * (t-b);
        ans = min(ans, area);
    }

    for(auto [x, y]: point[cur]) {
        int tl = min(l, x);
        int tr = max(r, x);
        int tt = max(t, y);
        int tb = min(b, y);

        if(ans > (tr - tl) * (tt - tb)) {
            dfs(cur+1, tl, tr, tt, tb);
        }
    }
}

int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    for(int i=0; i<N; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        point[k].push_back({x, y});
    }
    for(int i=1; i<=K; i++) {
        sort(point[i].begin(), point[i].end(),greater<ii>());
    }
    dfs(1, INT32_MAX, INT32_MIN, INT32_MIN, INT32_MAX);
    assert(ans != INT32_MAX);
    cout << ans;

   return 0;
}

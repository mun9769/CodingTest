#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

ll n, m;
ll arr[10066];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for(int i=1; i<=m; i++)
        cin >> arr[i];

    ll l = -1, r = 2'000'000'000LL * 30;
    ll done = 0;

    while(l + 1 < r) {
        ll mid = (l + r) / 2; // 시간

         ll cnt = 0;
//        done = 0;
        for(int i=1; i<=m; i++) {
            if(mid > 0)
                cnt += mid / arr[i] + 1;
        }

        if(cnt >= n or mid == 0) {
            r = mid;
        }
        else {
            l = mid;
            done = cnt;
        }
    }

    int ans = -1;

    for(int i=1; i<=m; i++) {
        if(r % arr[i] == 0) {
            done++;
            if(done == n) {
                ans = i;
                break;
            }
        }
    }
    cout << ans;

}

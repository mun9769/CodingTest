#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 2e9
#define Mxn 1'001

int T;
ll n, m;
ll num;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        vector<ll> A;

        cin >> n >> m;
        for(int i=0; i<n; i++)
            cin >> num, A.push_back(num);

        ll lft = 1, rht = *max_element(A.begin(), A.end()); // 1'000'000'000'000'000'000;
        ll mid;

        while(lft <= rht) {
            mid = (lft + rht) / 2;

            ll sum = 0;
            for(int i=0; i<A.size(); i++)
                sum += A[i] / mid;

            if(sum >= m)
                lft = mid + 1;
            else
                rht = mid - 1;
        }


        cout <<'#'<<tc<<' ';
        cout << rht << '\n';
    }
}
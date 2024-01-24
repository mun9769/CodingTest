#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 2e9
#define Mxn 1'001

int T;
ll n, p;
ll num;
bool grass[1'000'004];
int st, en;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        cin >> n >> p;
        vector<int> english;

        for(int i=0; i<n; i++) {
            cin >> num;
            english.push_back(num);
            grass[num] = true;
        }

        st = *english.begin();
        en = *english.rbegin();

        int lft = p+1, rht = 400'001;

        while(lft + 1 < rht) {
            int mid = (lft + rht) / 2;

            int days = 0;
            for(int i=0; i<mid-1; i++)
                days += grass[i];

            bool possible = false;

            for(int i=mid-1; i<=en; i++) {
                days += grass[i];
                if(days + p >= mid) {
                    possible = true;
                    break;
                }
                days -= grass[i - mid + 1];
            }

            if(possible)
                lft = mid;
            else
                rht = mid;
        }

        cout <<'#'<<tc<<' ';
        cout << lft << '\n';

        fill(grass, grass + en+3, false);
    }
}
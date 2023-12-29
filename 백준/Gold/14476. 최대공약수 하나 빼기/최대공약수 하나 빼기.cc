#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n;
int arr[1'000'005];
int lft[1'000'005];
int rht[1'000'005];
int answer = INT32_MIN;
int answer_k;

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

void setup() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
}

void solution() {
    lft[1] = arr[1];
    rht[n] = arr[n];

    for(int i=2; i<=n; i++) {
        lft[i] = gcd(arr[i], lft[i-1]);
    }
    for(int i=n-1; i>=1; i--) {
        rht[i] = gcd(arr[i], rht[i+1]);
    }
    int num = 0;
    for(int i=1; i<=n; i++) {
        int l = lft[i-1];
        int r = rht[i+1];

        if(i == 1) l = r;
        if(i == n) r = l;

        num = gcd(l, r);

        if(arr[i] % num == 0) continue;

        if(answer < num) {
            answer = num;
            answer_k = arr[i];
        }
    }
}

int main() {
    setup();

    solution();

    if(answer == INT32_MIN) cout << -1;
    else cout << answer << ' ' << answer_k ;
}

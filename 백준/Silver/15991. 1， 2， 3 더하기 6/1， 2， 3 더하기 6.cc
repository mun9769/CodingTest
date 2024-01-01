#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define mod 1'000'000'009


int n;
ll g[100'005];
ll f[100'005];



int main()
{

    g[1] = 1; g[2] = 2; g[3] = 4;
    for(int i = 4; i<=100'000; i++) {
        g[i] = (g[i-3] + g[i-2]) % mod;
        g[i] = (g[i] + g[i-1]) % mod;
        // g[i] = g[i-3] + g[i-2] + g[i-1];
    }

    f[1] = 1; f[2] = 2; f[3] = 2;

    for(int i=4; i<=100'000; i++) {
        if((i) % 2 == 0) {f[i] += g[i/2] % mod; f[i] %= mod; }
        if((i-1) % 2 == 0) {f[i] += g[(i-1)/2] % mod; f[i] %= mod; }
        if((i-2) % 2 == 0) {f[i] += g[(i-2)/2] % mod; f[i] %= mod; }
        if((i-3) % 2 == 0) {f[i] += g[(i-3)/2] % mod; f[i] %= mod; }
    }

    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        cout << f[num] << '\n';
    }
}
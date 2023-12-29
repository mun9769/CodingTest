#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n, m;
int arr[100'005];
void solution() {
    for(int i=1; i<n; i++) {
        arr[i+1] += arr[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    solution();

    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << '\n';
    }


}

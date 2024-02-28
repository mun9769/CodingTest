#include <bits/stdc++.h>
using namespace std;

const int inf = 987654321;

int n;
int k;
string str;
int a, b;
int R;
bool vis[1002][1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> R;
    int ans = 0;

    while(vis[a][b] == false) {
        vis[a][b] = true;
        ans++;
        if(a + b + 2 < R) {
            a++;
            b++;
        }
        else {
            a /= 2;
            b /= 2;
        }
    }
    cout << ans;


    return 0;
}

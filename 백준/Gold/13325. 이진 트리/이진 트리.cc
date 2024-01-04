#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 2'200'003


int k;
int score[Mxn];
int mx;
int layer_k_th;
int layer_k_1th;


ll answer;

void setup() {
    cin.tie(0) ->sync_with_stdio(0);

    cin >> k;
    for(int i=2; i<=pow(2, k+1) - 1; i++) { cin >> score[i]; answer += score[i]; }
    layer_k_th = pow(2, k);
    layer_k_1th = pow(2, k+1);
}

void mkscore() {
    for(int i=2; i<=pow(2, k) - 1; i++) {
        score[i*2] += score[i];
        score[i*2+1] += score[i];
    }

    for(int i=pow(2,k); i<=pow(2,k+1)-1; i++) {
        mx = max(mx, score[i]);
    }
}

int dfs(int cur) {
    if(layer_k_th <= cur and cur < layer_k_1th)
        return mx - score[cur];

    int lft = dfs(2 * cur);
    int rht = dfs(2 * cur + 1);

    answer += max(lft, rht) - min(lft, rht);

    return min(lft, rht);
}

int main() {
    setup();

    mkscore();
    answer += dfs(2);
    answer += dfs(3);

    cout << answer;

}

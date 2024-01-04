#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 100'003


int n, m;
vector<int> chd[Mxn];
int p[Mxn];
int score[Mxn];

void mktree() {
    for(int i=2; i<=n; i++) {
        int parent = p[i];
        chd[parent].push_back(i);
    }
}


void setup() {
    cin.tie(0) ->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> p[i];

    mktree();
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        score[a] += b;
    }
}
void bfs() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({1, score[1]});

    while(pq.size()) {
        auto [id, acc] = pq.top();
        pq.pop();

        cout << acc << ' ';

        for(auto nxt: chd[id]) {
            pq.push({nxt, acc + score[nxt]});
        }
    }
}

int main() {
    setup();

    bfs();

}

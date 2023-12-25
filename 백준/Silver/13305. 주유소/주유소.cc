#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n;
int price[100'002];
int dist[100'002];
int sum_dist[100'002];

ll min_cost[100'002];


void setup() {
    cin >> n;
    for(int i=0; i<n-1; i++) cin >> dist[i];
    for(int i=0; i<n; i++) cin >> price[i];

    int sum = 0;
    for(int i=n-2; i>=0; i--) {
        sum += dist[i];
        sum_dist[i] = sum;
    }
    for(int i=0; i<100'002; i++) min_cost[i] = LLONG_MAX;
}

ll dfs(int cur) {
    if(min_cost[cur] != LLONG_MAX) return min_cost[cur];

    ll result = price[cur] * (ll)sum_dist[cur]; // 현재에서 쭉 달리면 나오는 가격

    for(int i = cur+1; i<n-1; i++) {
        ll goal_dist = sum_dist[cur] - sum_dist[i];
        ll need_money = goal_dist * price[cur];

        result = min(result,
                     dfs(i) + need_money);
    }

    return min_cost[cur] = result;
}

int main() {
    setup();
    bool all_ones = std::all_of(price, price + n-1, [](int x) { return x == 1; });
    if(all_ones) cout << sum_dist[0];
    else cout << dfs(0) << endl;

}

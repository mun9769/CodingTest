#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

int T;
int n, d, c;

vector<ii> graph[10'003];
int cost[10'003];
int result = 0;
int cnt = 0;

void dijkstra(int start) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	result = 0;
	cnt = 0;

	pq.push({ 0, start });
	cost[start] = 0;

	while (pq.size()) {
		int here = pq.top().second;
		int firstToHere = pq.top().first;
		pq.pop();

		if (cost[here] < firstToHere)
			continue;

		result = max(result, cost[here]);
		cnt++;

		for (auto ele : graph[here]) {
			int there = ele.first;
			int c = ele.second;
			if (cost[there] > cost[here] + c) {
				cost[there] = cost[here] + c;
				pq.push({ cost[there], there });
			}
		}
	}
}

int main() {
	init;
	cin >> T;
	while (T-- > 0) {
		cin >> n >> d >> c;
		for (int i = 0; i < 10'003; i++) graph[i].clear();
		fill(cost, cost + n + 2, INT32_MAX);

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a, s }); // { to, cost }
		}

		dijkstra(c);

		cout << cnt << ' ' << result << '\n';
	}
}

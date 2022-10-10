#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

int minvisited[200'002];
int dp[200'002];


void bfs(int n) {
	queue<int> q;
	q.push(n);
	minvisited[n] = 1;
	dp[n] = -1;

	while (q.size()) {
		auto here = q.front();
		q.pop();

		for (int next : {here - 1, here + 1, here * 2}) {
			if (next < 0) continue;
			if (next > 200'001) continue;
			if (minvisited[next] == 0) {
				q.push(next);
				minvisited[next] = minvisited[here] + 1;
				dp[next] = here;
			}
			if (next == k) {
				return;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	bfs(n);

	cout << minvisited[k] - 1 << endl;
	int link = k;
	stack<int> s;

	while (true) {
		s.push(link);
		link = dp[link];
		if (link == -1) break;
	}
	while (s.size()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

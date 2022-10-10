#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

int visited[200'003];
int fastTime = INT32_MAX;
int cnt[200'003];

void bfs(int n) {
	queue<int> q;
	q.push(n);

	visited[n] = 1;
	cnt[n] = 1;
	while (q.size()) {
		int here = q.front();
		q.pop();

		if (visited[here] > fastTime) break;

		for (int next : { here - 1, here + 1, 2 * here }) {
			if (next > 200'001) continue;
			if (next < 0) continue;

			if (visited[next] == 0) {
				q.push(next);
				visited[next] = visited[here] + 1;
				cnt[next] += cnt[here];
			}
			else if (visited[next] == visited[here] + 1) {
				cnt[next] += cnt[here];
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	if (N >= K) {
		cout << N - K << endl;
		cout << 1;
		return 0;
	}

	bfs(N);
	cout << visited[K] - 1 << endl;
	cout << cnt[K];


}

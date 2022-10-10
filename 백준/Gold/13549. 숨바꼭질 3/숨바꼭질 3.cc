#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

int minvisited[200'002];
int cnt[200'002];


void bfs(int n) {
	queue<int> q;
	q.push(n);
	minvisited[n] = 1;

	while (q.size()) {
		auto here = q.front();
		q.pop();

		for (int next : {here * 2}) {
			if (next > 200'001) continue;
			if (minvisited[next] > minvisited[here] || minvisited[next] == 0) {
				q.push(next);
				minvisited[next] = minvisited[here];
			}
		}

		for (int next : {here - 1, here + 1}) {
			if (next < 0) continue;
			if (next > 200'001) continue;
			if (minvisited[next] > minvisited[here] + 1 || minvisited[next] == 0) {
				q.push(next);
				minvisited[next] = minvisited[here] + 1;
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

	cout << minvisited[k] - 1;

}

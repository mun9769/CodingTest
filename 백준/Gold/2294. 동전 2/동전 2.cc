#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

vector<int> coin;
int d[10'003];
queue<int> q;
int n;
int k;

int bfs() {
	while (q.size()) {
		auto here = q.front(); q.pop();

		if (here == k) {
			return d[here];
		}

		for (auto c : coin) {
			int there = here + c;
			if (there < 10001 && d[there] == 0) {
				q.push(there);
				d[there] = d[here] + 1;
			}
		}
	}
	return -1;
}

int main() {
	init;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		if (n > 10'000) continue;
		coin.push_back(n);
		d[n] = 1;
		q.push(n);
	}
	cout << bfs();
}
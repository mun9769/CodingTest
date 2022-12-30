#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
#include <set>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>
#define ll long long
#define bigNum 987654321

int channel;
int n;
vector<int> broken;
vector<int> active;
int minCnt[500'003];


int big = 987654321;
int bigCnt = 987654321;

bool canPush(int from, int to) {
	if (to > 500'000 && big > to && bigCnt > minCnt[from] + 1) {
		big = to;
		if (minCnt[from] != 987654321) {
			bigCnt = min(bigCnt, minCnt[from] + 1);
		}
		return false;
	}
	if (to < 0 || to > 500'000) return false;
	if (minCnt[from] + 1 >= minCnt[to]) return false;

	return true;
}

int bfs() {
	int now = 0;
	queue<int> q;
	q.push(now);
	minCnt[now] = 0;
	while (q.size()) {
		int here = q.front(); q.pop();
		for (auto ele : active) {
			int there = here * 10 + ele;
			if (canPush(here, there)) {
				q.push(there);
				minCnt[there] = minCnt[here] + 1;
			}
		}
	}
	return -1;
}

int main() {
	init;
	cin >> channel;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		active.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		active.erase(remove(active.begin(), active.end(), num), active.end());
	}
	fill(minCnt, minCnt + 500'002, 987654321);

	bfs();

	minCnt[100] = 0;

	if (n != 10) {
		minCnt[0] = active[0] + 1;
	}
	else {
		minCnt[0] = 100;
	}

	if (minCnt[channel] == bigNum) {
		int i = 1;
		bool flag = true;
		while (i <= 500'000 && flag) {
			int to = channel + i;
			if (to <= 500'000 && minCnt[to] != 987654321) {
				minCnt[channel] = min(minCnt[channel], minCnt[to] + i);
				flag = false;
			}
			to = channel - i;
			if (to > 0 && minCnt[to] != 987654321) {
				minCnt[channel] = min(minCnt[channel], minCnt[to] + i);
				flag = false;
			}
			i++;
		}
		minCnt[channel] = min(minCnt[channel], big - channel + bigCnt);
		minCnt[channel] = min(minCnt[channel], minCnt[0] + channel);
	}

	for (int i = 1; i < 100; i++) {
		minCnt[100 - i] = min(minCnt[100 - i], i);
		minCnt[100 + i] = min(minCnt[100 + i], i);
	}
	cout << minCnt[channel];


}
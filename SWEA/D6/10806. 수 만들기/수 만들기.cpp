#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cassert>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


int T;
int n, k;
int arr[20];

ll run() {

		unordered_map<ll, ll> m;
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		pq.push({ 0, k });
		m[k] = 0;

		while (pq.size()) {
			pll top = pq.top();
			ll cnt = top.first;
			ll x = top.second;
			pq.pop();

			if (cnt > m[x])
				continue;
			if (x <= 1)
				return cnt + x;

			for (int i = 0; i < n; i++) {
				int newX = x / arr[i];
				ll newCnt = cnt + x % arr[i];

				if (m.find(newX) != m.end() && newCnt >= m[newX])
					continue;
				pq.push({ newCnt, newX }); 
				m[newX] = newCnt;
			}
		}
		return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cin >> k;

		cout << '#' << tc << ' ';
		cout << run() << '\n';
	}

	return 0;
}
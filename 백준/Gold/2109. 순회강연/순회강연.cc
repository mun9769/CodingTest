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
int n;
ii univ[10'003];
priority_queue<int> pq;

bool cmp(ii& a, ii& b) {
	return a.second > b.second;
}

int main() {
	init;
	cin >> n;
	int mxDay = 0;
	for (int i = 0; i < n; i++) {
		cin >> univ[i].first >> univ[i].second;
		mxDay = max(mxDay, univ[i].second);
	}

	sort(univ, univ + n, cmp);
	int result = 0;

	int i = 0;
	for (int day = mxDay; day > 0; day--) {

		while (i < n && univ[i].second >= day) {
			pq.push(univ[i].first);
			i++;
		}
		if (pq.size()) {
			result += pq.top(); pq.pop();
		}
	}
	cout << result;
}
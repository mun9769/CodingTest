#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int arr[200'005];

unordered_map<int, int> lft;
unordered_map<int, int> rht;

ll preSum[200'005];

int main() {
	setbuf(stdout, NULL);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (lft.find(arr[i]) != lft.end()) {
			rht[arr[i]] = i;
		}
		else {
			lft[arr[i]] = i;
		}
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		preSum[i] = sum;
	}

	ll ans = 0;
	int cnt = 0;

	for (auto x : lft) {
		int val = x.first;
		int l = x.second;
		int r;

		if (rht.find(val) == rht.end()) {
			r = l;
		}
		else {
			r = rht[val];
		}
		
		ll ssum = preSum[r] - preSum[l - 1];

		if (ans < ssum) {
			ans = ssum;
			cnt = 1;
		}
		else if (ans == ssum) {
			cnt++;
		}
	}
	cout << ans << ' ' << cnt;

	return 0;
}

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int arr[200'005];
int sArr[200'005];

unordered_map<int, int> offset;

int main() {
	setbuf(stdout, NULL);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sArr[i] = arr[i];
	}

	sort(sArr, sArr + n);
	for (int i = 0; i < n; i++) {
		offset[sArr[i]] = i;
	}

	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		int cur = offset[arr[i]];
		int nxt = offset[arr[i + 1]];

		if (abs(cur - nxt) != 1) {
			ans++;
		}
	}
	cout << ans;


	return 0;
}

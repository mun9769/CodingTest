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


int num;
int i;

int n;
ii arr[103];
int dp[103];

bool cmp(ii& a, ii& b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int involve(ii& a, ii& b) {
	if (a.first >= b.first && a.second >= b.second)
		return true;
	return false;
}

int recur(int here) {
	if (dp[here] != -1) {
		return dp[here];
	}
	int ret = 0;
	for (int i = here + 1; i <= n; i++) {
		if(involve(arr[here], arr[i]))
			ret = max(ret, recur(i));
	}
	dp[here] = ret + 1;
	return ret + 1;
}

int main() {
	init;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) { swap(a, b); }

		arr[i].first = a;
		arr[i].second = b;
	}
	arr[n].first = arr[n].second = INT32_MAX;

	fill(dp, dp + n + 1, -1);

	sort(arr, arr + n + 1, cmp);
	cout << recur(0) - 1;




}
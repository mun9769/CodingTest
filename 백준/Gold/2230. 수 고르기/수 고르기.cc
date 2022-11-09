#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define ii pair<int, int>

int n;
int m;
int arr[100'003];

int main() {
	init;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int result = INT32_MAX;

	for (int i = 0; i < n - 1; i++) {
		int here = arr[i];
		auto iter = lower_bound(arr, arr + n, here + m);

		if (*iter == 0) continue;

		result = min(*iter - here, result);
	}
	cout << result;
}
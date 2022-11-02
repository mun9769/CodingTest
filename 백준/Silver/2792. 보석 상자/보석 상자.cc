#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int jewelryCnt[300'003];


int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n >> m;
	int maxJewelry = 0;
	for (int i = 0; i < m; i++) {
		cin >> jewelryCnt[i];
		maxJewelry = max(maxJewelry, jewelryCnt[i]);
	}
	int l = 1;
	int r = maxJewelry;
	int mid = 0;
	vector<int> result;

	while (l <= r) {
		mid = (l + r) / 2;

		int kinder = 0;
		for (int i = 0; i < m; i++) {
			int cnt = jewelryCnt[i];

			if (cnt % mid == 0)
				kinder += cnt / mid;
			else
				kinder += cnt / mid + 1;
		}

		if (kinder > n) {
			l = mid + 1;
		}
		else if (kinder <= n) {
			result.push_back(mid);
			r = mid - 1;
		}
	}
	sort(result.begin(), result.end());
	cout << result[0];
}

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

int T;
int n;
ii L[1'000'003];

int main() {
	init;
	cin >> n;
	int from, to;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		L[i] = { from, to };
	}
	sort(L, L + n);
	L[n] = { INT32_MAX, INT32_MAX };

	int result = 0;
	int l = L[0].first;
	int r = L[0].second;
	for (int i = 0; i < n; i++) {
		if (r <= L[i].first) {
			result += r - l;
			l = L[i].first;
			r = L[i].second;
		}
		else if (L[i].first <= r && r <= L[i].second) {
			r = L[i].second;
		}
	}
	result += r - l;
	cout << result;
}
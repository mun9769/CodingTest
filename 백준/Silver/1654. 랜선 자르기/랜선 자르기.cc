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

#define ull unsigned long long

ull k, n;
ull lan[10'003];

int main() {
	init;
	cin >> k >> n;
	ull l = 1;
	ull r = 0;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		r = max(r, lan[i]);
	}
	ull answer = 0;

	while (l <= r) {
		ull middle = (l + r) / 2; 
		ull cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += lan[i] / middle;
		}

		if (cnt >= n) {
			l = middle + 1;
			answer = middle;
		}
		else {
			r = middle - 1;
		}
	}
	cout << answer;

}
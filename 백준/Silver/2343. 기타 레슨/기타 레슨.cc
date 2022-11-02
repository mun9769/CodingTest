#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;


int n, m;
int lecture[100'003];

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n >> m;

	int l = 1;
	int r = 0;

	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		l = max(l, lecture[i]);
		r += lecture[i];
	}

	int result = r;

	while (l <= r) {
		int mid = (l + r) / 2;

		int blueray = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int time = lecture[i];

			if (sum + time > mid) {
				sum = time;
				blueray++;
			}
			else if (sum + time == mid) {
				sum = 0;
				blueray++;
			}
			else if (sum + time < mid) {
				sum += time;
			}
		}
		if (sum > 0)
			blueray++;

		if (blueray <= m) {
			result = mid;
			r = mid - 1;
		}
		else if (blueray > m) {
			l = mid + 1;
		}
	}
	cout << result;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define ii pair<int, int>


int N, M;
int L;
int rest[55];

int main() {
	init;
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++)
		cin >> rest[i];

	rest[N] = 0;
	rest[N + 1] = L;
	sort(rest, rest + N + 2);

	int l = 1;
	int r = L;
	int result = 0;

	while (l <= r) {
		int dis = (l + r) / 2;

		
		int cnt = 0;
		for (int i = 0; i < N + 1; i++) {

			int interval = rest[i + 1] - rest[i];

			if (interval % dis == 0) cnt += interval / dis - 1;
			else cnt += interval / dis;
		}

		if (cnt > M) {
			l = dis + 1;
		}
		else {
			r = dis - 1;
			result = dis;
		}
	}
	cout << result;

}

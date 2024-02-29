#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll A[200'005];
ll F[200'005];
ll prefix[200'005];
bool possible[200'005];

int main() {
	setbuf(stdout, NULL);
	cin.tie(0)->sync_with_stdio(0);
	fill(possible, possible + 200'005, true);
	cin >> n;

	for (int i = 0; i <= n; i++) {
		cin >> A[i] >> F[i];
	}
	ll ss = 0;
	for (int i = 0; i <= n; i++) {
		ss += F[i];
		prefix[i] = ss;
	}

	ll cur = A[0];
	ll oil = F[0];
	for (int i = 1; i <= n; i++) {
		ll need = A[i] - cur;
		if (oil < need) {
			possible[i] = false;
			break;
		}
		cur = A[i];
		oil -= need;
		oil += F[i];
	}

	int mm = 0;
	for (int i = 1; i <= n; i++) {
		if (possible[i] == false) {
			possible[i + 1] = false;
			cout << -1 << ' ' << -1 << '\n';
			continue;
		}

		ll newA = A[i] - A[i - 1];
		ll newF = F[i - 1];

		ll oldA = A[i] - A[mm];
		ll oldF = prefix[i - 1];
		if (mm > 0) {
			oldF -= prefix[mm - 1];
		}

		if (newF - newA >= oldF - oldA) {
			mm = i - 1;
			cout << i - 1 << ' ' << newF - newA << '\n';
		}
		else {
			cout << mm << ' ' << oldF - oldA << '\n';
		}

	}

	return 0;
}

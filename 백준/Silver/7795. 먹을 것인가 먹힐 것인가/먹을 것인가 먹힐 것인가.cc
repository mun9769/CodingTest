#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

int T;
int a[20'003];
int b[20'003];
set<int> s;
int n, m;

int main() {
	init;
	cin >> T;
	while (T-- > 0) {
		cin >> n >> m;
		s.clear();
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		sort(b, b + m);

		int result = 0;

		for (int i = 0; i < n; i++) {
			int here = a[i];
			auto iter = lower_bound(b, b + m, here);

			int index = distance(b, iter);
			result += index;
		}

		cout << result << '\n';
	}
}

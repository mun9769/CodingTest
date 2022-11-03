#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

int n, m;
set<int> s;

int a[200'003];
int b[200'003];

int main() {
	init;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(b, b + m);

	int inter = 0;
	for (int i = 0; i < n; i++) {
		int here = a[i];

		auto iter = lower_bound(b, b + m, here);
		if (*iter == here) inter++;
	}
	cout << n + m - 2 * inter;

}

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


long long d[1001][1001];
int t;
int n, m;

int main() {
	init;
	cin >> t;

	d[1][1] = d[1][2] = d[1][3] = 1;
	d[2][2] = 1; d[2][3] = 2; d[2][4] = 3; d[2][5] = 2; d[2][6] = 1;
	d[3][3] = 1;

	for (int j = 4; j <= 20; j++) {
		d[3][j] = d[2][j - 1] + d[2][j - 2] + d[2][j - 3];
	}


	for (int i = 4; i <= 1000; i++) {
		for (int j = i; j <= 1000; j++) {
			long long a = d[i - 1][j - 1] % 1'000'000'009;
			long long b = d[i - 1][j - 2] % 1'000'000'009;
			long long c = d[i - 1][j - 3] % 1'000'000'009;
			d[i][j] = a + b + c;
			d[i][j] %= 1'000'000'009;
		}
	}
	while (t-- > 0) {
		int a, b;
		cin >> a >> b;
		cout << d[b][a] << '\n';
	}

}
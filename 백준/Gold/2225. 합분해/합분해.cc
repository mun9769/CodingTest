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

long long d[202][202];
int m, k;

#define mod 1'000'000'000

long long recur(int cnt, int n) {
	if (d[cnt][n] != INT32_MAX)
		return d[cnt][n];

	long long res = 0;
	for (int i = 0; i <= cnt; i++) {
		res += recur(i, n - 1);
		res %= mod;
	}
	res %= mod;
	d[cnt][n] = res;
	return res;

}

int main() {
	init;
	cin >> m >> k;
	for (int i = 0; i < 202; i++) {
		for (int j = 0; j < 202; j++) {
			d[i][j] = INT32_MAX;
		}
	}
	for (int i = 0; i < 202; i++) {
		d[i][0] = 1;
		d[i][1] = i;
		d[0][i] = 0;
		d[1][i] = 1;
	}
	cout << recur(k, m);

}
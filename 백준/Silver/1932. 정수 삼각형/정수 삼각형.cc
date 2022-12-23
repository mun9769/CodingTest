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


int table[502][502];

int dp[502][502];
int n;

int main() {
	init;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			table[i][j] += max(table[i - 1][j - 1], table[i - 1][j]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, table[n][i]);
	cout << res;
}
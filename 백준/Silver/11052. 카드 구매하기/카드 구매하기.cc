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


int n;
int P[1004];
int dp[1004];

int main() {
	init;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> P[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}
	cout << dp[n];
}
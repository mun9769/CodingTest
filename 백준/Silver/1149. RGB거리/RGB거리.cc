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


int num;
int i;

int n;
ii arr[103];
int dp[1003][3];




int main() {
	init;
	cin >> n;

	int a, b, c;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + b;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + c;
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

}
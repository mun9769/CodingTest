#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;


int dp[1005][1005];

void solution() {
	string a = "ACAYKP";
	string b = "CAPCAK";
	cin >> a >> b;
	int a_size = a.size();
	int b_size = b.size();


	for (int i = 0; i < a_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (a[i] == b[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
    	cout << dp[a_size][b_size];

}




int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	solution();
}

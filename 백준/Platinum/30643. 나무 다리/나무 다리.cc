#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1'000'000'007;


// 0은 아무것도 안닿은 블록
// 1은 왼쪽만
// 2는 오른쪽만
// 3은 둘다
ll board[1001][1001][4];
int w, l;

int main() {
	setbuf(stdout, NULL);
	cin.tie(0)->sync_with_stdio(0);
	cin >> w >> l;
	if (l == 2) {
		cout << 1;
		return 0;
	}

	board[1][1][1] = 1;
	board[1][l - 1][2] = 1;
	for (int i = 2; i < l - 1; i++) {
		board[1][i][0] = 1;
	}

	for (int i = 1; i < w; i++) {

		for (int j = 1; j < l; j++) {
			int lft = j - 1;
			int rht = j + 1;

			int x = 0;
			{ 
				x = 0;

				if (lft == 1) {
					board[i + 1][lft][1] += board[i][j][x];
				}
				else if (lft > 1) {
					board[i + 1][lft][x] += board[i][j][x];
				}

				board[i + 1][j][x] += board[i][j][x];

				if (rht == l - 1) {
					board[i + 1][rht][2] += board[i][j][x];
				}
				else if (rht < l - 1) {
					board[i + 1][rht][x] += board[i][j][x];
				}
			}
			{ 
				x = 1;

				if (lft == 1) {
					board[i + 1][lft][1] += board[i][j][x];
				}
				else if (lft > 1) {
					board[i + 1][lft][x] += board[i][j][x];
				}

				board[i + 1][j][x] += board[i][j][x];

				if (rht == l - 1) {
					board[i + 1][rht][3] += board[i][j][x];
				}
				else if (rht < l - 1) {
					board[i + 1][rht][x] += board[i][j][x];
				}
			}
			{ 
				x = 2;

				if (lft == 1) {
					board[i + 1][lft][3] += board[i][j][x];
				}
				else if (lft > 1) {
					board[i + 1][lft][x] += board[i][j][x];
				}

				board[i + 1][j][x] += board[i][j][x];

				if (rht == l - 1) {
					board[i + 1][rht][2] += board[i][j][x];
				}
				else if (rht < l - 1) {
					board[i + 1][rht][x] += board[i][j][x];
				}
			}
			{ 
				x = 3;

				if (lft == 1) {
					board[i + 1][lft][x] += board[i][j][x];
				}
				else if (lft > 1) {
					board[i + 1][lft][x] += board[i][j][x];
				}

				board[i + 1][j][x] += board[i][j][x];

				if (rht == l - 1) {
					board[i + 1][rht][x] += board[i][j][x];
				}
				else if (rht < l - 1) {
					board[i + 1][rht][x] += board[i][j][x];
				}
			}

			for (int k = 0; k < 4; k++) {
				board[i+1][lft][k] %= mod;
				board[i+1][j][k] %= mod;
				board[i+1][rht][k] %= mod;
			}
		}
	}

	ll ans = 0;
	for (int j = 1; j < l; j++) {
		ans += board[w][j][3];
	}
	cout << ans % mod;
	

	return 0;
}

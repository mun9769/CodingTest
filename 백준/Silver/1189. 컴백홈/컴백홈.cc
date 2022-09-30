#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <stack>
using namespace std;

int r, c, k;
int map[7][7];
bool check[7][7];

const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int result = 0;

bool canGo(int a, int b) {
	if (a < 1 || b < 1 || a > r || b > c) return false;
	if (map[a][b] == 1) return false;
	return true;
}
void dfs(int a, int b, int cnt) {
	if (cnt > k) return;
	else if (cnt == k && a == 1 && b == c) {
		result++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int x = a + dx[i];
		int y = b + dy[i];

		if (check[x][y] == false && canGo(x,y)) {
			check[x][y] = true;
			dfs(x, y, cnt + 1);
			check[x][y] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == '.')
				map[i + 1][j + 1] = 0;
			else
				map[i + 1][j + 1] = 1;
		}
	}

	check[r][1] = true;
	dfs(r, 1, 1);
	cout << result;

}

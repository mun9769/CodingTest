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

const int dx[] = { 0,-1,0,1 };
const int dy[] = { 1,0,-1,0 };

bool table[101][101];

// if (a == {1, 2}) //이거 되는지 확인

ii convertDir(ii& a) {
	for (int i = 0; i < 4; i++) {
		if (a == make_pair(dx[i], dy[i])) {
			int u = dx[(i + 1) % 4];
			int v = dy[(i + 1) % 4];
			return { u,v };
		}
	}
}
void makeDragon(int x, int y, ii initDir, int gen) {
	vector<vector<ii>> dragon(11);
	dragon[0].push_back(initDir);
	table[x][y] = true;
	x += initDir.first;
	y += initDir.second;
	table[x][y] = true;

	for (int i = 1; i <= gen; i++) {
		for (int z = i - 1; z >= 0; z--) {
			for (int j = dragon[z].size() - 1; j >= 0; j--) {
				ii newDir = convertDir(dragon[z][j]);
				dragon[i].push_back(newDir);
			}
		}
		for (int j = 0; j < dragon[i].size(); j++) {
			ii Dir = dragon[i][j];
			x += Dir.first;
			y += Dir.second;
			table[x][y] = true;
		}
	}
}
int n;
int main() {
	init;

	cin >> n;
	while (n-- > 0) {
		int x, y;
		int dir;
		int gen;
		cin >> x >> y >> dir >> gen;
		makeDragon(y, x, { dx[dir], dy[dir] }, gen);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (table[i][j] && table[i + 1][j] && table[i][j + 1] && table[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans;

}
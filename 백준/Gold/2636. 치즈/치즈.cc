#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define ii pair<int, int>

#define SIZE 102

int map[SIZE][SIZE];
bool check[SIZE][SIZE];
int n, m;
vector<ii> zeros;
vector<ii> ones;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

bool canGo(int a, int b) {
	if (a<0 || b<0 || a>n + 1 || b>m + 1) return false;
	if (map[a][b] == 1) return false;
	return true;
}

void dfs(int a, int b) {
	check[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int xx = a + dx[i];
		int yy = b + dy[i];

		if (map[xx][yy] == 1) {
			ones.push_back({ xx,yy });
		}

		if (!check[xx][yy] && canGo(xx, yy)) {
			dfs(xx, yy);
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}

	int result = 0;
	zeros.push_back({ 0,0 });

	int lastCnt = 0;

	while (true) {
		if (zeros.empty()) {
			break;
		}
		for (int i = 0; i < zeros.size(); i++) {
			ii tmp = zeros[i];
			if (check[tmp.first][tmp.second] == false) {
				dfs(tmp.first, tmp.second);
			}
		}
		zeros.clear();

		if (ones.empty()) break;
		sort(ones.begin(), ones.end());
		ones.erase(unique(ones.begin(), ones.end()), ones.end());
		lastCnt = ones.size();

		for (ii ele : ones) {
			map[ele.first][ele.second] = 0;
			zeros.push_back(ele);
		}
		ones.clear();
		result++;
	}
	cout << result<< "\n";
	cout << lastCnt;

}

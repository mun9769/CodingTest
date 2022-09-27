#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
#define ii pair<int, int>

string str;
int n, m;
int original[10][10];
int map[10][10];

vector<ii> zeros;

vector<ii> selected;
vector<ii> originalQ;
queue<ii> q;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int result = 0;

bool canGo(int a, int b) {
	if (a<1 || b<1 || a>n || b > m) return false;
	if (map[a][b] == 1) return false;
	return true;
}

bool first = false;

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				map[i][j] = original[i][j];

		while (!q.empty()) q.pop();
		for (auto i : originalQ) q.push(i);

		while (!q.empty()) {
			ii front = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int xx = front.first + dx[i];
				int yy = front.second + dy[i];
				if (map[xx][yy] != 2 && canGo(xx, yy)) {
					map[xx][yy] = 2;
					q.push({ xx,yy });
				}
			}
		}
		int zeroCnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 0) zeroCnt++;
				// map[i][j] = original[i][j];
			}

		result = max(result, zeroCnt);
		return;
	}

	for (int i = idx; i < zeros.size(); i++) {
		ii tmp = zeros[i];
		original[tmp.first][tmp.second] = 1;
		dfs(i + 1, cnt + 1);
		original[tmp.first][tmp.second] = 0;
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
			original[i][j] = map[i][j];
			if (map[i][j] == 0) zeros.push_back({ i,j });
			if (map[i][j] == 2) originalQ.push_back({ i,j });
		}

	dfs(0, 0);

	cout << result;

}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <stack>
using namespace std;

#define ii pair<int, int>

int n, m;
int grid[53][53];
int visited[53][53];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

bool canGo(int nx, int ny) {
	if (nx <1 || ny < 1 || nx > n || ny > m) return false;
	if (grid[nx][ny] == 0)return false;
	if (visited[nx][ny] > 0) return false;

	return true;
}
int result = 0;

void bfs(int a, int b) {
	queue<ii> q;
	memset(visited, 0, sizeof(visited));

	q.push({a,b});
	visited[a][b] = 1;
	while (q.size()) {
		ii here = q.front();
		q.pop();
		// tie 그거 보기
		int x = here.first;
		int y = here.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (canGo(nx, ny)) {
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
				result = max(result, visited[nx][ny]);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'W')
				grid[i + 1][j + 1] = 0;
			else
				grid[i + 1][j + 1] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 1) {
				int cnt = 0;
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (grid[nx][ny] == 1) cnt++;
				}
				if (cnt == 4) continue;

				bfs(i, j);
			}
		}
	}
	cout << result - 1;
 }

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define ii pair<int, int>
int N, L, R;

int mapCopy[52][52];
int map[52][52];
bool visited[53][53];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

bool canGo(int nx, int ny) {
	if (nx <1 || ny < 1 || nx > N || ny > N) return false;
	if (visited[nx][ny]) return false;

	return true;
}

void bfs(int a, int b) {
	memset(visited, false, sizeof(visited));
	queue<pair<int,int>> q;
	q.push({ a,b });
	visited[a][b] = true;

	int cnt = 0;
	int sum = 0;
	vector<ii> v;
	while (q.size()) {
		ii here = q.front();
		q.pop();

		int x = here.first;
		int y = here.second;

		v.push_back(here);
		sum += map[x][y];
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			int gap = abs(map[x][y] - map[nx][ny]);
			if (gap < L || R < gap) continue;

			if (canGo(nx, ny)) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	int uni = sum / cnt;
	for (auto vi : v) {
		mapCopy[vi.first][vi.second] = uni;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
			mapCopy[i][j] = num;
		}

	int result = 0;
	while (true) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				bfs(i, j);
			}
		}

		// copyMap 복사
		bool stop = true;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] != mapCopy[i][j]) {
					map[i][j] = mapCopy[i][j];
					stop = false;
				}
			}
		}

		if (stop) break;

		result++;
	}
	cout << result;
}

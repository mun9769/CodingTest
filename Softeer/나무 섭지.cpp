#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int inf = 1e9;
const int MXN = 1005;

char board[MXN][MXN];
int visited[MXN][MXN];
int trace[MXN][MXN];

int n, m;
vector<ii> ghost;
ii st, en;

vector<ii> offsets = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

bool canGoGhost(int x, int y, int nx, int ny) {
	if (nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
	// if (visited[x][y] >= visited[nx][ny]) return false;
	if (visited[nx][ny] != inf) return false;

	return true;
}

bool canGoPlayer(int x, int y, int nx, int ny) {
	if (nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
	if (board[nx][ny] == '#') return false;
	if (trace[nx][ny] > 0) return false;

	if (visited[nx][ny] <= trace[x][y] + 1) return false;

	return true;
}

void bfsGhost() {
	queue<ii> q;
	for (ii pos : ghost) {
		visited[pos.first][pos.second] = 1;
		q.push(pos);
	}

	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (ii& offset : offsets) {
			int nx = x + offset.first;
			int ny = y + offset.second;

			if (canGoGhost(x, y, nx, ny)) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}

		}
	}
}

bool bfsPlayer() {
	queue<ii> q;
	q.push(st);
	trace[st.first][st.second] = 1;

	while (q.size()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (ii& offset : offsets) {
			int nx = x + offset.first;
			int ny = y + offset.second;

			if (canGoPlayer(x, y, nx, ny)) {
				trace[nx][ny] = trace[x][y] + 1;
				q.push({ nx, ny });

				if (nx == en.first and ny == en.second) {
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '#') {
				board[i][j] = '#';
			}
			else if (c == 'G') {
				ghost.push_back({ i, j });
			}
			else if (c == 'D') {
				en = { i, j };
			}
			else if (c == 'N') {
				st = { i, j };
			}
		}
	}

	for (int i = 0; i < n + 1; i++) {
		fill(visited[i], visited[i] + m + 1, inf);
	}
	bfsGhost();
	bool possible = bfsPlayer();
	if (possible) cout << "Yes";
	else cout << "No";
}

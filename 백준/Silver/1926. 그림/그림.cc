#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <stack>
using namespace std;

#define SIZE 503
int n, m;
int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

bool canGo(int a, int b) {
	if (a<1 || b < 1 || a>n || b>m) return false;
	if (visited[a][b] == true) return false;
	if (map[a][b] == 0) return false;

	return true;
}

queue<pair<int, int>> q;

int result;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
		}
	}
	int pieceCnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				q.push({ i,j });
				pieceCnt++;
			}
			int bulk = 0;
			while (!q.empty()) {
				pair<int, int> here = q.front();
				q.pop();
				bulk++;

				int x = here.first;
				int y = here.second;
				visited[x][y] = true;

				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (canGo(nx, ny)) {
						q.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
			result = max(bulk, result);
		}
	}
	cout << pieceCnt << endl;
	cout << result;

}

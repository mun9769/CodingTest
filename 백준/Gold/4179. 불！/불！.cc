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
#define SIZE 1002

struct iii {
	int x;
	int y;
	int t;
};

queue<iii> fq;
queue<iii> pq;

int r, c;

int map[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool visitedPlayer[SIZE][SIZE];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

bool canGo(int nx, int ny) {
	if (nx <1 || ny < 1 || nx > r || ny > c) return false;
	if (visited[nx][ny] == true) return false;
	if (map[nx][ny] == 0) return false;

	return true;
}

bool canGoPlayer(int nx, int ny) {
	if (visitedPlayer[nx][ny] == true) return false;
	if (map[nx][ny] == 0) return false;
	if (map[nx][ny] == 2) return false;

	return true;

}

void fireBfsOneTime() {
	auto front = fq.front();
	int t = front.t;
	while (fq.size() && fq.front().t == t) {
		auto here = fq.front();
		fq.pop();
		int x = here.x;
		int y = here.y;
		int t = here.t;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (canGo(nx, ny)) {
				fq.push({ nx,ny,t + 1 });
				map[nx][ny] = 2;
				visited[nx][ny] = true;
			}
		}
	}
}

int result = INT32_MAX;

void playerBfsOneTime() {
	int t = pq.front().t;
	while (pq.size() && pq.front().t == t) {
		auto here = pq.front();
		pq.pop();
		int x = here.x;
		int y = here.y;
		if (map[x][y] == 2) continue;
		int t = here.t;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > r || ny > c) {
				result = min(result, t + 1);
				break;
			}
			if (canGoPlayer(nx, ny)) {
				pq.push({ nx,ny, t + 1 });
				visitedPlayer[nx][ny] = true;
			}
		}
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			switch (s[j]) {
			case '#':
				map[i + 1][j + 1] = 0;
				break;
			case 'J':
				map[i + 1][j + 1] = 1;
				pq.push({ i + 1, j + 1, 0 });
				break;
			case 'F':
				map[i + 1][j + 1] = 2;
				fq.push({ i + 1,j + 1,0 });
				break;
			case '.':
				map[i + 1][j + 1] = 3;
				break;
			}
		}
	}

	bool fail = false;
	while (true) {
		// 플레이어가 못움직이면
		if (result != INT32_MAX)
			break;
		if (pq.empty()) {
			fail = true;
			break;
		}
		playerBfsOneTime();
		fireBfsOneTime();
	}
	if (fail)
		cout << "IMPOSSIBLE";
	else
		cout << result;
 }

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define ii pair<int, int>


int initGrid[10][10];
int grid[10][10];
int n, m;
int initZero = 0;
int zero = 0;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

bool canGo(int nx, int ny) {
	if (nx <1 || ny < 1 || nx > n || ny > m) return false;
	if (grid[nx][ny] == 6) return false;

	return true;
}

class Turret {
public:
	int _state;
	int _model;
	int _x;
	int _y;

public:
	void one() {
		int nx = _x + dx[_state];
		int ny = _y + dy[_state];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[_state];
			ny += dy[_state];
		}
	}
	void two() {
		int nx = _x + dx[_state];
		int ny = _y + dy[_state];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[_state];
			ny += dy[_state];
		}
		int reverseState = (_state + 2) % 4;
		nx = _x + dx[reverseState];
		ny = _y + dy[reverseState];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[reverseState];
			ny += dy[reverseState];
		}

	}
	void three() {
		int nx = _x + dx[_state];
		int ny = _y + dy[_state];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[_state];
			ny += dy[_state];
		}
		int sideState = (_state + 1) % 4;
		nx = _x + dx[sideState];
		ny = _y + dy[sideState];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[sideState];
			ny += dy[sideState];
		}

	}
	void four() {
		int nx = _x + dx[_state];
		int ny = _y + dy[_state];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[_state];
			ny += dy[_state];
		}
		int sideState = (_state + 1) % 4;
		nx = _x + dx[sideState];
		ny = _y + dy[sideState];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[sideState];
			ny += dy[sideState];
		}
		int threeState = (_state + 2) % 4;
		nx = _x + dx[threeState];
		ny = _y + dy[threeState];
		while (canGo(nx, ny)) {
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = 7;
				zero--;
			}
			nx += dx[threeState];
			ny += dy[threeState];
		}
	}
	void five() {

		for (int i = 0; i < 4; i++) {
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			while (canGo(nx, ny)) {
				if (grid[nx][ny] == 0) {
					grid[nx][ny] = 7;
					zero--;
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}

	void cctv() {
		switch (_model) {
		case 1: one(); break;
		case 2: two(); break;
		case 3: three(); break;
		case 4: four(); break;
		case 5: five(); break;
		default: cout << "wrong cctv()"; break;
		}
	}
};

vector<Turret> turret;


int result = INT32_MAX;

void dfs(int here) {
	if (here == turret.size()) {

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				grid[i][j] = initGrid[i][j];
		zero = initZero;

		for (auto ele : turret) {
			ele.cctv();
		}
		result = min(result, zero);
		return;
	}

	for (int i = 0; i < 4; i++) {
		//		if (turret[here]._model == 5) {
		//			dfs(here + 1);
		//			continue;
		//		}
		turret[here]._state++;
		turret[here]._state %= 4;
		dfs(here + 1);
	}
}

int main() {
	init;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> initGrid[i][j];
			int ele = initGrid[i][j];
			if (ele >= 1 && ele <= 5)
				turret.push_back({ 0,ele,i,j });
			else if (ele == 0)
				initZero++;

		}
	}


	dfs(0);
	cout << result;


}

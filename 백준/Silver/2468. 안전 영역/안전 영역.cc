#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#define ii pair<int,int> 

std::map<int, vector<ii>> m;

#define SIZE 103

int area[SIZE][SIZE];
bool sinkArea[SIZE][SIZE];
int N;
bool check[SIZE][SIZE];

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

bool canGo(int x, int y) {
	if (x < 1 || y < 1) return false;
	if (x > N || y > N) return false;
	if (sinkArea[x][y] == true) return false;
	if (check[x][y] == true) return false;

	return true;
}

void dfs(int x, int y) {

	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (canGo(xx, yy))
			dfs(xx, yy);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> area[i][j];
			m[area[i][j]].push_back({ i,j });
		}
	}

	int result = 1;

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		for (int i = 0; i < (int)iter->second.size(); i++) {
			ii xy = iter->second[i];
			sinkArea[xy.first][xy.second] = true; // true이 잠긴거
		}

		memset(check, false, sizeof(check));
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (sinkArea[i][j] == false && check[i][j] == false) {
					check[i][j] = true;
					dfs(i, j);
					cnt++;
				}
			}
		}
		result = std::max(result, cnt);
	}

	cout << result;
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
#define ii pair<int, int>

int N, M;
int grid[53][53];
map<ii, int> chickenDis[53][53];

vector<ii> houses;
vector<ii> outDak;
vector<ii> selected;
struct threeInt {
	int x;
	int y;
	int dis;
};

int selectedVal;
int result = INT32_MAX;
void dfs(int index) {

	if (selected.size() == M) {
		selectedVal = 0;
		for (auto aHouse : houses) {
			int small = INT32_MAX;
			for (auto aOutDak : selected) {
				int dis = abs(aHouse.first - aOutDak.first) + abs(aHouse.second - aOutDak.second);
				small = min(small, dis);
			}
			selectedVal += small;
		}
		result = min(result, selectedVal);
		return;
	}

	for (int i = index; i < outDak.size(); i++) {
		selected.push_back(outDak[i]);
		dfs(i + 1);
		selected.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1)
				houses.push_back({ i,j });
			if (grid[i][j] == 2)
				outDak.push_back({ i,j });
		}
	dfs(0);

	cout << result;

}

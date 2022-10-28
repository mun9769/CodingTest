#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[12];
int n;
int population[12];
bool visited[12];

vector<int> jin;
vector<int> bo;

void checkJin(int here) {
	visited[here] = true;
	
	for (auto there : graph[here]) {
		if (visited[there]) continue;
		if (find(jin.begin(), jin.end(), there) == jin.end()) continue;

		checkJin(there);

	}
}
void checkBo(int here) {
	visited[here] = true;

	for (auto there : graph[here]) {
		if (visited[there]) continue;
		if (find(bo.begin(), bo.end(), there) == bo.end()) continue;

		checkBo(there);
	}
}
int result = INT32_MAX;

void BitOper() {
	for (int i = 1; i < (1 << n) - 1; i++) {
		jin.clear();
		bo.clear();
		memset(visited, false, sizeof(visited));

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { jin.push_back(j + 1); }
			else { bo.push_back(j + 1); }
		}

		bool allCheckJin = true;
		bool allCheckBo = true;

		int costJin = 0;
		int costBo = 0;

		checkJin(jin[0]);
		for (int region : jin) {
			costJin += population[region];
			if (visited[region] == false) {
				allCheckJin = false;
				break;
			}
		}
		checkBo(bo[0]);
		for (int region : bo) {
			costBo += population[region];
			if (visited[region] == false) {
				allCheckJin = false;
				break;
			}
		}

		if (!allCheckJin || !allCheckBo) continue;
		result = min(result, abs(costJin - costBo));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> population[i];

	for (int i = 1; i <= n; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int adj;
			cin >> adj;
			graph[i].push_back(adj);
		}
	}

	BitOper();

	if (result == INT32_MAX) cout << -1;
	else cout << result;

}

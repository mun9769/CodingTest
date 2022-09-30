#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

map<int, vector<int>> hackedComs;


vector<int> childs[10'002];

bool check[10'002];

int dfs(int p) {

	if (check[p] == true) return 0;
	check[p] = true;

	int sum = 1;

	for (int i = 0; i < childs[p].size(); i++) {
		int there = childs[p][i];
		if (check[there] == false)
			sum += dfs(childs[p][i]);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		childs[b].push_back(a);
	}


	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		int hacked = dfs(i);

		hackedComs[hacked].push_back(i);
	}
	auto iter = hackedComs.rbegin();

	auto& v = iter->second;

	sort(v.begin(), v.end());

	for (auto i : v) { cout << i << " "; }
	
}

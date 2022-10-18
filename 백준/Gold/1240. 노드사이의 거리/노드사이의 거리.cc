#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

int n, m;

#define ii pair<int ,int>
#define ll long long

vector<ii> graph[1003];
ll visitCost[1003];
bool visited[1003];

void dfs(int here) {

	for (auto i = 0; i < graph[here].size(); i++) {
		auto info = graph[here][i];
		int there = info.first;
		int cost = info.second;

		if (visited[there] == true)
			continue;

		visitCost[there] = visitCost[here] + cost;
		visited[there] = true;

		dfs(there);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	while (n-- > 1) {
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[a].push_back({ b,cost });
		graph[b].push_back({ a,cost });
	}

	while (m-- > 0) {
		memset(visitCost, 0, sizeof(visitCost));
		memset(visited, 0, sizeof(visited));
		int from, to;
		cin >> from >> to;

		visited[from] = true;
		dfs(from);

		cout << visitCost[to] << '\n';
	}

	return 0;
}

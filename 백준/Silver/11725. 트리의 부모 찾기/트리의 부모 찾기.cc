#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;


int n;

vector<int> graph[100'002];

int parent[100'002];

void dfs(int here) {

	for (auto i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];

		if (parent[there] != 0)
			continue;
		parent[there] = here;

		dfs(there);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	parent[1] = -1;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i]<<'\n';
	}
}

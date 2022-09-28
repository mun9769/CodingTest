#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define ii pair<int, int>

#define SIZE 55
int n;

vector<int> childs[SIZE];
bool check[SIZE];
int result = 0;

void search(int top) {
	check[top] = true;

	if (childs[top].empty()) {
		result++;
		return;
	}

	for (int i = 0; i < childs[top].size(); i++) {
		int there = childs[top][i];
		search(there);
	}
}

int parent[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		parent[i] = num;
		if (num == -1) continue;
		childs[num].push_back(i);
	}
	int m;
	cin >> m;

	if (parent[m] == -1) {
		parent[m] = -2;
	}
	else {
		int a = parent[m];
		vector<int>& v = childs[a];
		v.erase(remove(v.begin(), v.end(), m), v.end());
	}


	for (int i = 0; i < n; i++) {
		if (parent[i] == -2) continue;
		if (parent[i] == -1) {
			search(i);
		}
	}

	cout << result;

}

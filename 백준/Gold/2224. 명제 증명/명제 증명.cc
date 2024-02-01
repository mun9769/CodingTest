#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n;
int board[60][60];

string str;


int c2i(char c) {
	if (std::isupper(c)) {
		return c - 'A';
	}
	else {
		return c - 'a' + 26;
	}
}

int src;
vector<ii> v;
bool visited[55];

void dfs(int cur) {

	visited[cur] = true;

	for (int i = 0; i < 52; i++) {
		if (board[cur][i] == 1 and visited[i] == false) {
			dfs(i);
			v.push_back({ src, i });
		}
	}
}

char i2c(int x) {
	if (0 <= x and x < 26) {
		return 'A' + x;
	}
	else {
		return 'a' + (x-26);
	}
}


int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		char st = *str.begin();
		char en = *str.rbegin();

		int s = c2i(st);
		int e = c2i(en);

		board[s][e] = 1;
	}

	for (int i = 0; i < 52; i++) {
		fill(visited, visited + 55, 0);
		src = i;
		dfs(i);
	}
	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << '\n';
	for (ii& pos : v) {
		char from = i2c(pos.first);
		char to = i2c(pos.second);
		
		cout << from << " => " << to << '\n';
	}
}

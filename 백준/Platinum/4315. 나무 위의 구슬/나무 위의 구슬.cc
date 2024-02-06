#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
#include <functional>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

#define Mxn 10005

int n;
int a, b, c;
vector<int> ch[Mxn];
int subtree[Mxn];
int p[Mxn];

int cnt[Mxn];
int need[Mxn];
ll answer;


int getRoot(int cur) {
	while (p[cur] != -1) {
		cur = p[cur];
	}
	return cur;
}

void dfs(int cur) { 
	int pid = p[cur];
	if (ch[cur].empty()) {
		cnt[pid] += cnt[cur] - 1;
		answer += abs(cnt[cur] - 1);
		cnt[cur] = 1; 
		return;
	}

	for (int nxt : ch[cur]) {
		dfs(nxt);
	}
	if (pid != -1) {
		cnt[pid] += cnt[cur] - 1;
		answer += abs(cnt[cur] - 1);
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	// freopen("sample_input.txt", "r", stdin);

	while (true) {
		cin >> n;
		if (n == 0) break;

		memset(p, -1, sizeof(p));
		memset(cnt, 0, sizeof(cnt));
		memset(ch, {}, sizeof(ch));
		answer = 0;
		

		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			cnt[a] = b;
			for (int j = 0; j < c; j++) {
				int id;
				cin >> id;
				ch[a].push_back(id);
				p[id] = a;
			}
		}

		int root = getRoot(a);

		dfs(root);

		cout << answer << '\n';

	}
}

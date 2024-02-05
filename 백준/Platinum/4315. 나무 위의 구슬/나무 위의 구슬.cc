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
int getSubtree(int cur) {
	int result = 1;
	for (int nxt : ch[cur]) {
		result += getSubtree(nxt);
	}
	return subtree[cur] = result;
}

void giveToChild(int cur, int given) {

	cnt[cur] += given;
	need[cur] -= given;

	for (int nxt : ch[cur]) {
		if (need[nxt] > 0 and cnt[cur] > 1) {
			int give = min(cnt[cur] - 1, need[nxt]);
			cnt[cur] -= give;
			answer += give;
			giveToChild(nxt, give);
		}
	}
}

ii dfs(int cur) {  // 올린 것, 필요한 것
	if (ch[cur].empty()) {
		if (cnt[cur] > 0) {
			int tmp = cnt[cur] - 1;
			need[cur] = 0;
			cnt[cur] = 1;
			return { tmp, 0 };
		}
		else {
			need[cur] = 1;
			return { 0, 1 };
		}
	}

	need[cur] = 1;
	for (int nxt : ch[cur]) {
		ii k = dfs(nxt);
		answer += k.first;
		cnt[cur] += k.first;

		need[cur] += k.second;
	}
	need[cur] = max(0, need[cur] - cnt[cur]);

	giveToChild(cur, 0);

	assert(need[cur] >= 0);


	if (need[cur] > 0) {
		return { 0, need[cur] };
	}
	else { // no need
		int tmp = cnt[cur] - 1;
		cnt[cur] = 1;
		return { tmp, need[cur] };
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	while (true) {
		cin >> n;
		if (n == 0) break;

		fill(p, p + Mxn, -1);
		fill(subtree, subtree + Mxn, 0);
		fill(cnt, cnt + Mxn, 0);
		fill(need, need + Mxn, 0);
		for (int i = 0; i < Mxn; i++)
			ch[i].clear();
		
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
		int _ = getSubtree(root);

		dfs(root);

		cout << answer << '\n';

	}
}

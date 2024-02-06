#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;


int n;
ll k;
ii ch[200'006];

int answer;

void dfs(int cur, ll step) {

	int l = ch[cur].first;
	int r = ch[cur].second;

	// no child
	if (l == -1 and r == -1) {
		answer = cur;
		return;
	}

	// only child
	else if (l == -1 and r != -1) {
		dfs(r, step);
	}
	else if (l != -1 and r == -1) {
		dfs(l, step);
	}

	// two child
	else {
		if (step % 2 == 0) {
			dfs(l, step / 2);
		}
		else if (step % 2 == 1){
			dfs(r, step / 2);
		}
	}

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		ch[i] = { u, v };
	}
	cin >> k;

	dfs(1, k-1);
	cout << answer;
}

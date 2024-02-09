#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n, m;
int nxt[5'000'000][30];
int gid = 1;

bool chk[5'000'000];
int ans;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		int cur = 0;
		for (int x = 0; x < str.size(); x++) {
			int c2i = str[x] - 'a';

			if (nxt[cur][c2i] > 0) {
				cur = nxt[cur][c2i];
			}
			else {
				nxt[cur][c2i] = gid++;
				cur = nxt[cur][c2i];
			}
		}
		chk[cur] = true;
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		int cur = 0;
		bool found = true;
		for (int x = 0; x < str.size(); x++) {
			int c2i = str[x] - 'a';

			if (nxt[cur][c2i] > 0) {
				cur = nxt[cur][c2i];
			}
			else {
				found = false;
				break;
			}
		}
		if (!chk[cur]) found = false;

		if (found) {
			ans++;
		}
	}
	cout << ans;
	


}

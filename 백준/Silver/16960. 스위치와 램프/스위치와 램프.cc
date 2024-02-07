#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> collect[2005];
int num[2006];

int main()
{
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;
		vector<int> v;
		for (int i = 0; i < cnt; i++) {
			int aa;
			cin >> aa;
			v.push_back(aa);
			num[aa]++;
		}
		
		collect[i] = v;
	}
	bool answer = true;
	for (int i = 1; i <= m; i++) {
		if (num[i] <= 0) {
			answer = false;
			break;
		}
	}
	if (answer == false) {
		cout << '0'; 
		return 0;
	}
	answer = false;

	for (int i = 0; i < n; i++) {
		bool possible = true;
		for (auto x : collect[i]) {
			if (num[x] <= 1) 
				possible = false;
		}
		if (possible) {
			answer = true;
			break;
		}
	}
	cout << answer;

	return 0;
}

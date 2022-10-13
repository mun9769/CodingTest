#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

int ASize;
string A;

bool check[10];

string v;

bool canGo(int a, int b, char c) {
	if (c == '<') {
		return a < b;
	}
	else {
		return a > b;
	}
}
ll maxResult;
ll minResult = 9'999'999'999;

void dfs(int here) {
	if (here == (int)A.size()) {
		maxResult = max(maxResult, stoll(v));
		minResult = min(minResult, stoll(v));
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (check[i]) continue;
		if (canGo((*v.rbegin()) - '0', i, A[here]) == false)
			continue;

		check[i] = true;
		v.push_back(i + '0');

		dfs(here + 1);

		check[i] = false;
		v.pop_back();
	}
}

int main() {
	fastio;
	cin >> ASize;
	for (int i = 0; i < ASize; i++) {
		char c;
		cin >> c;
		A.push_back(c);
	}
	for (int i = 0; i < 10; i++) {
		check[i] = true;
		v.push_back(i + '0');
		dfs(0);
		v.pop_back();
		check[i] = false;
	}
	cout << maxResult << endl;
	ll ones = pow(10, ASize);
	if (minResult / ones == 0)
		cout << '0';
	cout << minResult << endl;
}

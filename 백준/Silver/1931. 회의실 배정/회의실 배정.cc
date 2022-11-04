#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define ii pair<int, int>
int n;
int last;
int s, e;
vector<ii> meeting;

int dp[100'003];

int main() {
	init;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		meeting.push_back({ e,s });
	}

	sort(meeting.begin(), meeting.end());

	int ans = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (t > meeting[i].second) continue;
		ans++;
		t = meeting[i].first;
	}
	cout << ans;

}

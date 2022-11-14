#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define ii pair<int, int>
int n;

int pos[1'000'003];
vector<int> tmp;

int main() {
	init;
	tmp.reserve(1'000'003);
	cin >> n;
	set<int> s;

	for (int i = 0; i < n; i++) {
		cin >> pos[i];
		tmp.push_back(pos[i]);
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.begin() + n), tmp.begin() + n);

	for (int i = 0; i < n; i++) {
		int target = pos[i]; 
		auto iter = lower_bound(tmp.begin(), tmp.end(), target);
		cout << iter - tmp.begin() << ' ';
	}

}

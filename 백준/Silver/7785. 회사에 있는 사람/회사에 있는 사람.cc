#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

int n;
std::unordered_set<string> s;

int main() {
	init;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, cmd;
		cin >> name >> cmd;

		if (cmd == "enter") {
			s.insert(name);
		}
		else if (cmd == "leave") {
			if (s.count(name)) {
				s.erase(name);
			}
		}
	}
	vector<string> v;
	for (auto i : s) {
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << '\n';
	}
}

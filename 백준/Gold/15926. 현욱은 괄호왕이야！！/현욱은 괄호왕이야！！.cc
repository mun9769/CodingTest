#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

int n;
string brace;
stack<char> s;

int result = 0;
int cnt = 0;

int main() {
	init;
	cin >> n;
	cin >> brace;

	for (int i = 0; i < brace.size(); i++) {
		if (brace[i] == '(') {
			s.push(i); cnt++;
			continue;
		}

		if (s.empty()) {
			result = max(result, cnt);
			cnt = 0;
			continue;
		}
		s.pop(); cnt++;

		if (s.empty()) {
			result = max(result, cnt);
		}
	}

	while (s.size()) s.pop();
	cnt = 0;

	for (int i = brace.size() - 1; i >= 0; i--) {
		if (brace[i] == ')') {
			s.push(i); cnt++;
			continue;
		}

		if (s.empty()) {
			result = max(result, cnt);
			cnt = 0;
			continue;
		}
		s.pop(); cnt++;

		if (s.empty()) {
			result = max(result, cnt);
		}
	}
	cout << result;

}

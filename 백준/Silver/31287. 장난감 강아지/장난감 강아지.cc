#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


string str;
int n, k;
ii move(char c) {
	if (c == 'U') return { -1, 0 };
	else if (c == 'R') return { 0, 1 };
	else if (c == 'L') return { 0, -1 };
	else if (c == 'D') return { 1, 0 };

	throw "moving error";
}

ii operator+(const ii& lhs, const ii& rhs) {
	int x = lhs.first + rhs.first;
	int y = lhs.second + rhs.second;
	return { x, y };
}
int main()
{
	ii pos = { 0, 0 };
	cin >> n >> k;
	cin >> str;
	string answer = "NO";
	for (int i = 0; i < min(n, k); i++) {
		for (auto c : str) {
			pos = pos + move(c);
			if (pos.first == 0 and pos.second == 0) {
				answer = "YES";
			}
		}
	}
	cout << answer;

}

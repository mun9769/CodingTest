#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define ii pair<int,int>

int T;
set<int> s;
map<int, int> m;
queue<int> q;

vector<int> fives;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp = 5;
	while (tmp > 0 && tmp < 1'000'000'001) {
		fives.push_back(tmp);
		tmp *= 5;
	}

	cin >> T;
	int t = T;
	while (t-- > 0) {
		int num;
		cin >> num;
		s.insert(num);
		q.push(num);
	}

	int twoCnt = 0;
	int fiveCnt = 0;

	auto iter = s.begin();
	vector<ii> v;
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		int number = *iter - *iter % 5;
		v.push_back({ *iter, number });
	}
	for (auto ele : v) {
		int sum = 0;
		for (int i = 0; i < fives.size(); i++) {
			int target = ele.second;
			int cnt = target / fives[i];
			if (cnt == 0) break;
			sum += target / fives[i];
		}
		m[ele.first] = sum;
	}

	while (T-- > 0) {
		int a = q.front();
		q.pop();

		cout << m[a] << "\n";
	}
}

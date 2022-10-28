#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct energy {
	int p;
	int f;
	int s;
	int v;
	int c;
	void operator+(const energy& rhs) {
		p += rhs.p;
		f += rhs.f;
		s += rhs.s;
		v += rhs.v;
		c += rhs.c;
	}
};

int n;
int mp, mf, ms, mv;

energy arr[18];
int result = INT32_MAX;
vector<int> resultV;
map<int, vector<vector<int>>> ret_v;

void bitOper() {
	for (int i = 1; i < (1 << n); i++) {
		energy _e{ 0,0,0,0,0 };
		vector<int> v;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				_e + arr[j];
				v.push_back(j + 1);
			}
		}

		if (_e.p >= mp && _e.f >= mf && _e.s >= ms && _e.v >= mv) {
			if (result >= _e.c) {
				result = _e.c;
				ret_v[result].push_back(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n;

	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].p;
		cin >> arr[i].f;
		cin >> arr[i].s;
		cin >> arr[i].v;
		cin >> arr[i].c;
	}

	bitOper();

	if (result == INT32_MAX) {
		cout << -1;
		return 0;
	}

	sort(ret_v[result].begin(), ret_v[result].end());
	cout << result << '\n';

	for (auto ele : ret_v[result][0]) {
		cout << ele << ' ';
	}

}

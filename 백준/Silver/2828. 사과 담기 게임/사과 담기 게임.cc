#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#define ii pair<int,int>
#define xx first
#define yy second

int N, M;
int J;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> J;

	ii pos = { 1, M };

	vector<int> v;
	for (int i = 0; i < J; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int result = 0;
	for (int i = 0; i < J; i++) {
		if (pos.yy < v[i]) {
			int distance = v[i] - pos.yy;
			result += distance;
			pos = { pos.xx + distance, v[i] };
		}
		else if (v[i] < pos.xx) {
			int distance = pos.xx - v[i];
			result += distance;
			pos = { v[i], pos.yy - distance };
		}
	}

	cout << result;

}

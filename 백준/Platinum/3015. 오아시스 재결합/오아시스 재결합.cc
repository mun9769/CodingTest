#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

int T;
int X, A, B;

int n;
int arr[500'003];
vector<ii> s;

int main() {
	init;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	s.push_back({ arr[0],1 });
	long long cnt = 0;

	for (int i = 1; i < n; i++) {
		while (s.size() && s.back().first < arr[i]) {
			cnt += s.back().second;
			s.pop_back();
		}

		if (s.size() && s.back().first == arr[i]) {
			cnt += s.back().second;
			s.back().second++;
			if (s.size() > 1) cnt++;
		}
		else if (s.size() && s.back().first != arr[i]) {
			cnt++;
			s.push_back({ arr[i],1 });
		}
		else if (s.empty()) {
			s.push_back({ arr[i],1 });
		}
	}

	cout << cnt;
}
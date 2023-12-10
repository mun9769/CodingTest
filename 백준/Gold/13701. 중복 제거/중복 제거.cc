#include <bits/stdc++.h>

using namespace std;

bitset<33554432> bits;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int num;
		cin >> num;

		if (cin.eof())
			break;

		if (!bits[num]) {
			bits[num] = 1;
			cout << num << ' ';
		}
	}

	return 0;
}
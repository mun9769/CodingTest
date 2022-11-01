#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int d[19];

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> T;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i < 14; i++) {
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}

	while (T-- > 0) {
		int n;
		cin >> n;
		cout << d[n] << endl;
	}
}

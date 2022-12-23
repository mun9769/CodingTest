#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
#include <set>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>


long long d[100'003];
int n;

int main() {
	init;
	cin >> n;
	fill(d, d + 100'002, INT32_MAX);

	for (int i = 1; i * i <= 100'002; i++) {
		d[i*i] = 1;
	}

	for (int i = 2; i <= 100'000; i++) {
		for (int j = 1; i - j * j > 0; j++) {
			d[i] = min(d[i - j * j] + 1, d[i]);
		}
	}
	cout << d[n];

}
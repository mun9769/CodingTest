#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T;

int cost[1003][1003];

int main() {
	string a, b;
	cin >> a >> b;

	a.insert(a.begin(), '-');
	b.insert(b.begin(), '-');

	for (int i = 0; i <= a.length(); i++)
		cost[i][0] = i;
	for (int i = 0; i <= b.length(); i++)
		cost[0][i] = i;

	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			if (a[i] == b[j]) {
				cost[i][j] = cost[i - 1][j - 1];
			}
			else {
				cost[i][j] = min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1])) + 1;
			}

		}
	}

	cout << cost[a.length() - 1][b.length() - 1] << endl;

}

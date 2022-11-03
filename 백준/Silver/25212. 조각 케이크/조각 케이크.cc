#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

int n;
int arr[11];
int result;

int main() {
	init;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i < (1 << n); i++) {
		vector<int> select;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { // 이게 잘되는지 확인하기
				select.push_back(arr[j]);
			}
		}

		double sum = 0;
		for (auto s : select) {
			sum += (double)1 / (double)s;
		}
		if (sum >= 0.99 && sum <= 1.01) {
			result++;
		}
	}
	cout << result;

}

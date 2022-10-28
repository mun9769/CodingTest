#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[1004];
int cnt[1004];

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i < n; i++) {
		int here = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			int prev = arr[j];
			if (prev < here) {
				cnt[i] = max(cnt[i], cnt[j] + 1);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, cnt[i]);
	}
	cout << result + 1;

}

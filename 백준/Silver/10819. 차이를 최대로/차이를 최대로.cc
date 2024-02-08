#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[50];
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;

	sort(arr, arr + n);
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		ans = max(ans, sum);
	} while (next_permutation(arr, arr + n));
	
	cout << ans;
}

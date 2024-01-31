#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;
using ii = pair<int, int>;


int arr[10'005];
vector<int> A;
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		int num = arr[i + 1] - arr[i];
		A.push_back(num);
	}
	sort(A.begin(), A.end());

	long long result = 0;
	for (int i = 0; i < n - 1 - k + 1; i++) {
		result += A[i];
	}

	cout << result;

}

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[50];
int main(void) {
	string str;
	cin >> str;
	for (auto c : str) {
		arr[c - '0']++;
	}
	int sum = arr[6] + arr[9];
	if (sum % 2 == 0) arr[6] = sum / 2;
	else arr[6] = sum / 2 + 1;
	arr[9] = 0;
	cout << *max_element(arr, arr + 10);
	
}

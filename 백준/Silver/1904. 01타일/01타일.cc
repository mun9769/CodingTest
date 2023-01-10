#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int arr[1'000'001];

int main()
{
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= 1'000'000; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746;
	}
	cout << arr[n];
	
}
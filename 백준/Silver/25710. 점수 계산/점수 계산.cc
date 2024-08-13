#include<iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <cmath>
#include <map>
#include <string>
#include <queue>
#include <deque>
using namespace std;
using ll = long long;

int n;
int arr[2002];

int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[num]++;
	}
	int ans = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] <= 0) continue;
		arr[i]--;
		for (int j = i; j < 1000; j++)
		{
			if (arr[j] <= 0) continue;
			arr[j]--;
			int mul = i * j;
			int sum = 0;
			while (mul > 0)
			{
				sum += mul % 10;
				mul /= 10;
			}
			ans = max(ans, sum);
			arr[j]++;
		}
		arr[i]++;
	}
	cout << ans;
}


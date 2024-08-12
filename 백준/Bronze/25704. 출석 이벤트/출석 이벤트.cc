#include<iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;
double n, p;

int main(int argc, char** argv)
{
	cin >> n >> p;
	int ans = p;
	if (n >= 5)
	{
		ans = min(ans, (int)(p - 500));
	}
	if (n >= 10)
	{
		ans = min(ans, (int)(p * 0.9));
	}
	if (n >= 15)
	{
		ans = min(ans, (int)(p - 2000));
	}
	if (n >= 20)
	{
		ans = min(ans, (int)(p * 0.75));
	}
    ans = max(ans, 0);
	cout << ans;
}


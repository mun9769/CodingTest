#include<iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
using ll = long long;

long long w, h;
long long k;
long long n, m;
map<ll, long long> vertical;
map<ll, long long> horizontal;
ll prv;
int main(int argc, char** argv)
{
	cin >> w >> h >> k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll cur;
		cin >> cur;
		horizontal[cur - prv]++;
		prv = cur;
	}
	horizontal[h - prv]++;

	prv = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll cur;
		cin >> cur;
		vertical[cur - prv]++;
		prv = cur;
	}
	vertical[w - prv]++;
	auto it = next(horizontal.begin());
	for (; it != horizontal.end(); it++)
	{
		it->second += prev(it)->second;
	}


	long long ans = 0;

	for (auto it = vertical.begin(); it != vertical.end(); it++)
	{
		ll desired = floor(k / (long long)it->first);

		auto hit = horizontal.lower_bound(desired);
		if (hit == horizontal.begin() and hit->first > desired)
			continue;
		if (hit == horizontal.end() or hit->first > desired)
			hit = prev(hit);


		ans += it->second * hit->second;
	}
	cout << ans;

}


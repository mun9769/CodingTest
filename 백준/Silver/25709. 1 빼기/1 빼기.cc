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
string s;
bool rst;

void do_()
{
	auto it = find(s.begin(), s.end(), '1');
	int ns = -1;
	if (it == s.end())
	{
		ns = stoi(s) - 1;
		s = to_string(ns);
	}
	else
	{
		s.erase(it);
		while (s.size() and *s.begin() == '0')
		{
			s.erase(s.begin());
		}
	}

	if (ns == 0 or s.empty())
	{
		rst = true;
	}
}


int main(int argc, char** argv)
{
	cin >> s;
	int ans = 0;
	while (true)
	{
		ans++;
		do_();
		if (rst == true)
		{
			break;
		}
	}
	cout << ans;
	
}


#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
#include <functional>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

#define Mxn 10005

int n;
int arr[1005];

set<int> s;
int answer;


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		int skip = *iter;

		for (int i = 0; i < n;) {

			int num = arr[i];
			int pos = i;
			int len = 0;

			while (arr[pos] == num || arr[pos] == skip) {
				if (arr[pos] == skip) {
					pos++;
				}
				else {
					len++;
					pos++;
				}
			}
			answer = max(answer, len);
			i = pos;
		}
	}
	cout << answer;
}

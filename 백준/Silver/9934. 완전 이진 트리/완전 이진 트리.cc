#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

vector<int> level[11];

int K;
vector<int> rules[22];

int main() {
	fastio;
	cin >> K;
	vector<int> v{ -1,1 };
	rules[2] = { -1,1 };

	for (int i = 2; i < 11; i++) {
		for (int j = 0; j < (int)rules[i].size(); j++) {
			rules[i + 1].push_back(rules[i][j]);
		}
		rules[i + 1].push_back(-i);
		rules[i + 1].push_back(i);

		for (int j = 0; j < (int)rules[i].size(); j++) {
			rules[i + 1].push_back(rules[i][j]);
		}
	}

	if (K == 1) {
		int num;
		cin >> num;
		cout << num;
	}

	int here = K;
	int cnt = pow(2, K) - 1;
	for(int i=0; i < cnt; i++){
		int num; 
		cin >> num;

		level[here].push_back(num);

		if(i < cnt -1)
			here += rules[K][i];
	}
	for (int i = 1; i <= K; i++) {
		for (auto i : level[i])
		{
			cout << i << " ";
		}
		cout << '\n';
	}
}

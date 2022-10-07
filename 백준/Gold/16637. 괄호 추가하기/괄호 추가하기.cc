#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n;
string s;

int oper(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

vector<int> num;
vector<char> oper_str;
int result = INT32_MIN;

void go(int here, int _num) {
	if (here == num.size() - 1) {
		result = max(result, _num);
		return;
	}

	int b = num[here + 1];
	int calc = oper(oper_str[here], _num, b);

	if (here == num.size() - 2) 
		result = max(result, calc);

	go(here + 1, oper(oper_str[here], _num, num[here + 1]));

	if (here >= num.size() - 2)
		return;

	int c = num[here + 2];
	calc = oper(oper_str[here + 1], b, c);

	int calcTwo = oper(oper_str[here], _num, calc);

	if (here == num.size() - 3) 
		result = max(result, calcTwo);

	go(here + 2, calcTwo);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper_str.push_back(s[i]);
	}

	go(0, num[0]);
	cout << result;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		getline(cin, str);
		if (str == ".") break;
		stack<char> s;

		bool flag = false;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}

			else if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					cout << "no\n";
					flag = true;
					break;
				}
				s.pop();
			}
			else if (str[i] == ']') {
				if (s.empty() || s.top() != '[') {
					cout << "no\n";
					flag = true;
					break;
				}
				s.pop();
			}
		}
		if (!flag && !s.empty()) { cout << "no\n"; continue; }
		if (!flag) cout << "yes\n";
	}

}

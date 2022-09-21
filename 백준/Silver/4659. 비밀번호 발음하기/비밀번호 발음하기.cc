#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const char vowel[] = { 'a','e','i','o','u' };

const char twice[] = { 'e', 'o' };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		cin >> s;
		if (s == "end") break;
		bool flag1 = false;
		bool flag2 = true;
		bool flag3 = true;

		int sequence = 0;
		int arr[30] = { 0, };
		for (int i = 0; i < (int)s.size(); i++) {
			for (int j = 0; j < 5; j++) {
				if (s[i] == vowel[j]) {
					flag1 = true;
					arr[i] = 1;
				}
			}
		}
		if (flag1 == false) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}

		for (int i = 0; i < (int)s.size() - 2; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) {
				flag2 = false;
				break;
			}
		}
		if (flag2 == false) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}

		for (int i = 0; i < (int)s.size() - 1; i++) {
			if (s[i] == 'e' || s[i] == 'o') {
				continue;
			}
			if (s[i] == s[i + 1]) {
				flag3 = false;
				break;
			}
		}
		if (flag3 == false) {
			cout << "<" << s << "> is not acceptable.\n";
			continue;
		}
		cout << "<" << s << "> is acceptable.\n";
	}
}

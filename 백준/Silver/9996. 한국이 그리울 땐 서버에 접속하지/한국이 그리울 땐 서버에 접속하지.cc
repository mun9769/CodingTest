#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string pattern;
	cin >> N;
	cin >> pattern;
	int index = pattern.find('*');

	string patternLeft = pattern.substr(0, index);
	string patternRight = pattern.substr(index + 1, pattern.size() - index - 1);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		bool flag = false;
		if (patternLeft.size() + patternRight.size() > s.size()) {
			cout << "NE" << endl;
			continue;
		}

		for (int j = 0; j < patternLeft.size(); j++) {
			if (s[j] != patternLeft[j]) {
				cout << "NE" << endl;
				flag = true;
				break;
			}
		}
		if (flag) continue;

		for (int j = patternRight.size() - 1; j >= 0; j--) {

			if (patternRight[j] != s[s.size() + j - patternRight.size()]) {
				cout << "NE" << endl;
				flag = true;
				break;
			}
		}

		if (flag) continue;

		cout << "DA" << endl;
	}
}

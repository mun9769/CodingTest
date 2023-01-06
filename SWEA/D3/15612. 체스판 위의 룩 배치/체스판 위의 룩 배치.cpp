#include<iostream>
#include <string>
using namespace std;

int table[8][8];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 8; j++) {
				if (s[j] == 'O') { table[i][j] = 1; cnt++; }
				else table[i][j] = 0;
			}
		}
		if (cnt != 8) {
			cout << "#" << test_case << " no\n";
			continue;
		}

		bool flag = true;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (table[i][j] == 1) {
					for (int x = 0; x < 8; x++) {
						if (x == i) continue;
						if (table[x][j] == 1) { flag = false; break; }
					}
					for (int y = 0; y < 8; y++) {
						if (y == j) continue;
						if (table[i][y] == 1) { flag = false; break; }
					}
				}
			}
		}
		if (flag) { cout << "#" << test_case << " yes\n"; }
		else { cout << "#" << test_case << " no\n"; }
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int H, W;

vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < W; j++) {
			if (s[j] == '.') {
				cout << -1 << " ";
				continue;
			}

			int n = 0;
			cout << n++ << " ";
			// j++; // 이 표현도 안좋은듯

			while (s[j + 1] == '.') { 
				cout << n++ << " ";
				j++; // while의 ()에다가 ++ 넣지 않는게 좋구나/
			}
		}
		cout << "\n";
	}
}

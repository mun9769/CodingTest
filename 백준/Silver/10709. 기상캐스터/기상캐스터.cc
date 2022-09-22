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
			int k = j + 1;
			while (k < W && s[k] == '.') { 
				// s[k++]이 == '.'이 왼쪽에 있으면 안된다.
				cout << n++ << " ";
				k++; // 괜히 while의 ()에다가 ++ 넣지 않는게 좋겟구나/
			}
			j = k - 1; // j에 값을 넣어서 올려주기
		}
		cout << "\n";
	}
}

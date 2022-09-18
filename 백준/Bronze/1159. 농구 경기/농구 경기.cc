#include <iostream>
using namespace std;

int arr[30];
bool flag = false;
int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		arr[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] > 4) {
			flag = true;
			cout << char(i + 'a');
		}
	}
	if (!flag) {
		cout << "PREDAJA";
	}
}

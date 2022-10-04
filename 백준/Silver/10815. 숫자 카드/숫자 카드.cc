#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

int N;
int M;
unordered_set<int> us;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		us.insert(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		// if (us.count(num)) {}
		if (us.find(num) != us.end()) {
			cout << 1 << " ";
		}
		else
			cout << 0 << " ";
	}
}

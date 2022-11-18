#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

int n;
std::unordered_set<string> s;

int main() {
	init;

	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		int c = a + b;
		result += c;
		pq.push(c);
	}
	cout << result;

}

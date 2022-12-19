#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
#include <set>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>


multiset<int> leftSet;
multiset<int> rightSet;

int n;
int main() {
	init;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		leftSet.insert(num);
		auto iter = leftSet.end();
		iter--; // rbegin()이 왜 안되지?

		rightSet.insert(*iter);

		leftSet.erase(iter);

		if (leftSet.size() < rightSet.size()) {
			auto iter2 = rightSet.begin();
			leftSet.insert(*iter2);
			rightSet.erase(iter2);
		}

		cout << *leftSet.rbegin() << "\n";
	}

}
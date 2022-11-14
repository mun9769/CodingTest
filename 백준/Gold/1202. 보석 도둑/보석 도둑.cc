#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#define ii pair<int, int>

int n, k;

ii bosuk[1'000'003];
int bag[300'003];


int main() {
	init;
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> bosuk[i].first >> bosuk[i].second;

	for (int i = 0; i < k; i++)
		cin >> bag[i];

	sort(bosuk, bosuk + n);
	sort(bag, bag + k);

	priority_queue<int> pq;

	int j = 0;
	long long result = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && bosuk[j].first <= bag[i]) {
			pq.push(bosuk[j].second);
			j++;
		}
		if (pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;

}

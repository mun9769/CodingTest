#include <string>
#include <vector>
#include<queue>
using namespace std;


int solution(int n, int k, vector<int> enemy) {
	int answer = -1;

	int l = 0;
	int r = enemy.size() - 1; // -1해?


	while (l <= r) {
		int middle = (l + r) / 2;
		long long sum = 0;
		priority_queue<int> pq;
		for (int i = 0; i <= middle; i++) {
			pq.push(enemy[i]);
			sum += enemy[i];
		}
		int cnt = k;
		while (pq.size() && cnt-- > 0) {
			sum -= pq.top(); pq.pop();
		}
		if (sum > n) {
			r = middle - 1;
		}
		else {
			l = middle  + 1;
			answer = middle;
		}
	}
	return answer + 1;
}
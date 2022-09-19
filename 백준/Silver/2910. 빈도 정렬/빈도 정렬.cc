#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define xx first
#define yy second
#define ull long long
#define tt tuple<ull, int, int> // 값, 개수, 첫 index
#define ii pair<int,int>

struct zzz {
	bool operator()(tt& a, tt& b) {
		if (get<1>(a) == get<1>(b)) {
			return get<2>(a) > get<2>(b);
		}
		return get<1>(a) < get<1>(b);
	}
};

int N;
long long C;


map<ull, ii> m;
priority_queue<tt,vector<tt>, zzz> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		ull num;
		cin >> num;
		if (m.count(num)) 
			m[num].first++;
		else
			m[num] = { 1, i };
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		tt tmp = { iter->first, iter->second.first, iter->second.second };
		pq.push(tmp);
	}

	while (!pq.empty()) {
		tt tmp = pq.top();
		pq.pop();

		for (int i = 0; i < get<1>(tmp); i++) {
			cout << get<0>(tmp) << " ";
		}
	}
}

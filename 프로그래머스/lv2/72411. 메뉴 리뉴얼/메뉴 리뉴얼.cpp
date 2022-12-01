#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int courseCnt[11];


vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	map<string, int> m;
	for (string order : orders) {
		for (int i = 0; i < 1 << order.size(); i++) {
			string result = "";
			int cnt = 0;
			for (int j = 0; j < order.size(); j++) {
				if (i & (1 << j)) {
					cnt++;
					result.push_back(order[j]);
				}
			}
			for (auto ele : course) {
				if (cnt != ele) continue;

				sort(result.begin(), result.end());
				m[result]++;
				int resSize = result.size();
				courseCnt[resSize] = max(courseCnt[resSize], m[result]);
			}
		}
	}
	for (auto iter : m) {
		int mySize = iter.first.size();
		int num = iter.second;
		if (courseCnt[mySize] < 2) continue;

		if (num == courseCnt[mySize]) {
			answer.push_back(iter.first);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
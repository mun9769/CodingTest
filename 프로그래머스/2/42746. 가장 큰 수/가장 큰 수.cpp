#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <string>
using namespace std;

bool cmp(string& a, string& b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;

	for (auto num : numbers)
		tmp.push_back(to_string(num));

	sort(tmp.begin(), tmp.end(), cmp);

	if (tmp[0] == "0") return "0";
	for (auto num : tmp)
		answer += num;
	return answer;
}

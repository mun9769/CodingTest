#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;
struct person {
	string name;
	bool isHidden;

	bool operator<(const person& rhs) const {
		return name < rhs.name;
	}
};


map<int, set<person>> mm;
int rr = 1;

void parseStr(string s) {
	int cnt = 3;
	string name;
	string score;
	string isHidden;

	s.find('"');
	while (cnt-- > 0) {
		int idx = s.find(':');
		if (cnt == 2) idx += 1;
		s.erase(0, idx+1);
		idx = 0;

		if (cnt == 2) {
			int r = s.find("\"");
			name = s.substr(0, r);
		}
		else if(cnt == 1){
			int r = s.find(',');
			score = s.substr(0, r);
		}
		else if (cnt == 0) {
			int r = s.find('}');
			isHidden = s.substr(0, r);
		}
	}

	int scoreInt = stoi(score);
	bool ih = stoi(isHidden);

	mm[scoreInt].insert({ name, ih });
}

int main() {
	setbuf(stdout, NULL);
	cin.tie(0)->sync_with_stdio(0);
	// freopen("sample_input.txt", "r", stdin);
	cin >> t;
	for(int z = 0; z<t; z++) {
		string str;
		cin >> str;
		if (z == 0) str.erase(str.begin());
		else if (z == t - 1) str.erase(str.end() - 1);

		parseStr(str);
	}

	for (auto it = mm.rbegin(); it != mm.rend(); it++) {
		int score = it->first;
		auto& li = it->second;

		for (auto lit = li.begin(); lit != li.end(); lit++) {
			if (lit->isHidden) continue;
			cout << rr << ' ' << lit->name << ' ' << score << '\n';
		}

		rr += li.size();
	}
	

	return 0;
}

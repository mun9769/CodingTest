#include<vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int n;
int q;

unordered_set<int> ss;

int main(int argc, char** argv)
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int id;
		cin >> id;
		vector<int> path;
		bool possible = true;
		int ans;
		while (id > 0) {
			path.push_back(id);
			id /= 2;
		}

		for (auto rit = path.rbegin(); rit != path.rend(); rit++) {
			int cur = *rit;
			auto found = ss.find(cur);
			if (found != ss.end()) {
				possible = false;
				ans = *found;
				break;
			}
		}

		if (possible) {
			ss.insert(path[0]);
			cout << "0\n";
		}
		else {
			cout << ans << '\n';
		}
	}
}


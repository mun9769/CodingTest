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

int n;

struct Node {
	string s;
	vector<Node*> children;
	int depth = 0;
	Node(string s) :s(s) {}

	Node* insert(string t) {
		for (auto ele : children) {
			if (ele->s == t)
				return ele;
		}
		Node* node = new Node(t);
		children.push_back(node);
		return node;
	}
	bool find(string t) {
		for (auto ele : children) {
			if (ele->s == t)
				return true;
		}
		return false;
	}
};

bool cmp(Node* a, Node* b) {
	return a->s < b->s;
}
Node* root = new Node("");

void dfs(Node* here, int depth) {
	sort(here->children.begin(), here->children.end(), cmp);

	for (int i = 0; i < depth; i++) {
		cout << "--";
	}
	if(depth != -1)
		cout << here->s << '\n';

	for (auto ele : here->children) {
		dfs(ele, depth + 1);
	}
}

int main() {
	init;
	cin >> n;
	while (n-- > 0) {
		int depth;
		cin >> depth;
		Node* cursor = root;
		for (int i = 0; i < depth; i++) {
			string s; cin >> s;

			cursor = cursor->insert(s);
		}
	}
	dfs(root, -1);




}
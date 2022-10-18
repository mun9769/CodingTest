#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

int n, m;

#define cc pair<char, char>

cc child[40];


void one(char here) {
	if (here == '.')
		return;

	int index = here - 'A';
	int left = child[index].first;
	int right = child[index].second;

	cout << here;
	if(left != '.')
		one(left);
	if(right != '.')
		one(right);
}
void two(char here) {
	if (here == '.')
		return;

	int index = here - 'A';
	int left = child[index].first;
	int right = child[index].second;

	if(left != '.')
		two(left);
	cout << here;
	if(right != '.')
		two(right);
}
void three(char here) {
	if (here == '.')
		return;

	int index = here - 'A';
	int left = child[index].first;
	int right = child[index].second;

	if(left != '.')
		three(left);
	if(right != '.')
		three(right);
	cout << here;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n-- > 0) {
		char p, c1, c2;

		cin >> p >> c1 >> c2;

		int parent = p - 'A';
		child[parent] = { c1, c2 };
	}

	one('A');
	cout << '\n';
	two('A');
	cout << '\n';
	three('A');


	return 0;
}

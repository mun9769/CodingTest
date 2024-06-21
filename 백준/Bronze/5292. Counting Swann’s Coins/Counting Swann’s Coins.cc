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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0 and i % 5 == 0) cout << "DeadMan\n";
		else if (i % 3 == 0) cout << "Dead\n";
		else if (i % 5 == 0) cout << "Man\n";
		else cout << i << ' ';
	}
}


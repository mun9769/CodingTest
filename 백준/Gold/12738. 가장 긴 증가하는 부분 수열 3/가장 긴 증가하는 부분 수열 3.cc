#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int n;
int lis[1'000'005];
int len;
int num;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		if (*lowerPos == 0)
			len++;
		*lowerPos = num;
	}
	cout << len;

}

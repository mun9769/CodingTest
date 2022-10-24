#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int arr[100'002];

int bs(int target) {
	int st = 0;
	int en = n-1;

	while (st <= en) {
		int mi = (st + en) / 2;
		
		if (arr[mi] < target) {
			st = mi + 1;
		}
		else if (target < arr[mi]) {
			en = mi - 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << bs(num) << '\n';
	}


	
	
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
	cin >> t;
	vector<int> a;
	a.reserve(10);
	while (t-- > 0)
	{
		int num;
		for (int i = 0; i < 10; i++) {
			cin >> num;
			a.push_back(num);
		}

		sort(a.begin(), a.end());
		cout << a[7] << endl;
		a.clear();
	}
}

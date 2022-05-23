#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	int n;
	cin >> n;

	while (n-- > 0)
	{
		int pos;
		cin >> pos;
		cin >> s;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (distance(s.begin(), it) != pos - 1)
				cout << *it;
		}
		cout << endl;
	}
}

#include <iostream>
#include <stack>
using namespace std;

int n;
int arr[1'000'004];
int nge[1'000'004];
stack<pair<int, int>> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		nge[i] = -1;
	}

	s.push({ 1, arr[1] });
	for (int i = 2; i <= n; i++)
	{
		while (!s.empty() && s.top().second < arr[i])
		{
			nge[s.top().first] = arr[i];
			s.pop();
		}
		s.push({ i, arr[i] });
	}
	for (int i = 1; i <= n; i++)
		cout << nge[i] << " ";
}

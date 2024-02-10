#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct s {
	s() {}
	s(int a, bool check) : a(a), check(check) {}
	int a = 0;
	bool check = false;
};

int t;
int arr[11];

int main()
{
	cin >> t;
	while(t-->0)
	{
		int n, m;
		int cnt = 1;
		cin >> n >> m;
		priority_queue<int> pq;
		queue<s> q;

		for (int i = 0; i < n; i++)
		{
			int paper;
			cin >> paper;
			pq.push(paper);
			if (i == m)
				q.push(s(paper, true));
			else
				q.push(s(paper, false));
		}
		while (true)
		{
			int top = pq.top();
			pq.pop();
			bool find = false;
			while (true)
			{
				if (q.front().a != top)
				{
					s tmp = q.front();
					q.pop();
					q.push(tmp);
				}
				else
				{
					if (q.front().check == false)
					{
						q.pop();
						cnt++;
						break;
					}
					else
					{
						find = true;
						break;
					}
				}
			}
			if (find)
				break;
		}
		cout << cnt << endl;
		
	}
}

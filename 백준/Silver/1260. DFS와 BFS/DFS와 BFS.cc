#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s;

vector<vector<int>> v(1003);
int map[1003][1003];
bool check[1003];
bool check2[1003];

queue<int> q;

void DFS(int vertex)
{
	check[vertex] = true;
	printf("%d ", vertex);

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false && map[vertex][i] == 1)
		{
			DFS(i);
		}
	}
}
int main()
{
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(s);
	printf("\n");

	check2[s] = true;
	for (int i = 1; i <= n; i++)
	{
		if (i == s)
			continue;
		if (map[s][i] == 1) {
			q.push(i);
			check2[i] = true;
		}
	}
	printf("%d ", s);

	while (!q.empty())
	{
		int top = q.front();
		printf("%d ", top);
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (i == top)
				continue;
			if (check2[i] == false && map[top][i] == 1) {
				q.push(i);
				check2[i] = true;
			}
		}
	}



	return 0;
}

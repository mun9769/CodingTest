#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define pii pair<int,int>
#define Size 102

int n, m;
int map[Size][Size];
int minDist[Size][Size];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct pos {
	pos() {}
	pos(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
	int x = 0;
	int y = 0;
	int cnt = 0;
};

queue<pos> q;
int result = INT32_MAX;	

int main()
{
	cin >> n >> m;
	string k[Size];

	for (int i = 1; i <= n; i++)
		cin >> k[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			map[i][j] = k[i].at(j-1) - '0'; //'0'이 48맞나? //at(j)말고 [j]해도 되나?
			minDist[i][j] = INT32_MAX;
		}

	q.push(pos(1, 1, 1));
	minDist[1][1] = 1;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (x == n && y == m)
		{
			if (result > cnt) { result = cnt; }
		}

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx<1 || yy < 1 || xx>n || yy > m)
				continue;

			if (map[xx][yy] == 1 && minDist[xx][yy] > cnt + 1)
			{
				q.push(pos(xx, yy, cnt + 1));
				minDist[xx][yy] = cnt + 1;
			}
		}
	}

	cout << result;



}

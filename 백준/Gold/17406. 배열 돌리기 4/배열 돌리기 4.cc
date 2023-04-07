#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;

int n, m, k;
int map[70][70];
int originMap[70][70];

struct oper {
	oper() {}
	oper(int r, int c, int s) :r(r), c(c), s(s) {}
	int r, c, s;
};

void rotateMap(int r, int c,int s)
{
	for (int a = 1; a <= s; a++)
	{
		for (int b = 0; b < 2 * a; b++)
		{
			int x = r - a + b;
			int y = c - a;
			std::swap(map[x][y], map[x + 1][y]);
		}
		for (int b = 0; b < 2 * a; b++)
		{
			int x = r + a;
			int y = c - a + b;
			std::swap(map[x][y], map[x][y + 1]);
		}
		for (int b = 0; b < 2 * a; b++)
		{
			int x = r + a - b;
			int y = c + a;
			std::swap(map[x][y], map[x - 1][y]);
		}
		for (int b = 0; b < 2 * a - 1; b++)
		{
			int x = r - a;
			int y = c + a - b;
			std::swap(map[x][y], map[x][y - 1]);
		}
	}
}
int result = INT32_MAX;

void isResult()
{
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= m; j++)
		{
			tmp += map[i][j];
		}
		if (tmp < result) result = tmp;
	}
}

void permutation(oper opers[], int depth, int N, int r)
{
	if (depth == r)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				map[i][j] = originMap[i][j];

		for (int i = 1; i <= k; i++)
		{
			rotateMap(opers[i].r, opers[i].c, opers[i].s);
		}
		isResult();

		return;
	}
	for (int i = depth; i < N; i++)
	{
		::swap(opers[depth], opers[i]);
		permutation(opers, depth + 1, N, r);
		::swap(opers[depth], opers[i]);
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			originMap[i][j] =map[i][j];
		}
	}
	int r, c, s;
	oper opers[10];
	for (int i = 1; i <= k; i++) {
		cin >> r >> c >> s;
		opers[i] = oper(r, c, s);
	}
	permutation(opers, 1, k+1, k+1);
	cout << result;
}

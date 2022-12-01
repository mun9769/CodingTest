#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int d[203][203];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			d[i][j] = INT32_MAX;

	for (int i = 0; i < fares.size(); i++) {
		int a = fares[i][0];
		int b = fares[i][1];
		int c = fares[i][2];
		d[a][b] = c;
		d[b][a] = c;
	}
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INT32_MAX) continue;
				if (d[k][j] == INT32_MAX) continue;
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	answer = INT32_MAX;
	for (int i = 1; i <= n; i++) {
		if (d[s][i] == INT32_MAX) continue;
		if (d[i][a] == INT32_MAX) continue;
		if (d[i][b] == INT32_MAX) continue;

		answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
	}
	return answer;
}
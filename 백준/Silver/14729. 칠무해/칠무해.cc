#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;
#define init ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define ii pair<int, int>

int T;
int n;

float score[10'000'003];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%f", &score[i]);
	sort(score, score + n);
	for (int i = 0; i < 7; i++)
		printf("%.3f\n", score[i]);
}
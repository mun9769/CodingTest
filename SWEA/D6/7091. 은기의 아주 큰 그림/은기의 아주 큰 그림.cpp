#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;

char eunPic[2004][2004];
char teaPic[2004][2004];
int tmp[2004][2004];
int tmp2[2004][2004];

const int rVal = 5;
const int cVal = 3;

int c2i(char c) {
    
    if (c == 'o') return 1;
    if (c == 'x') return 0;

    throw "error";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample_input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int answer = 0;
		int rPow = 1;
		int cPow = 1;
        int h, w, n, m;
        cin >> h >> w >> n >> m;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> eunPic[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> teaPic[i][j];
            }
        }

        int eunHash = 0;

        for (int i = 0; i < h; i++) {
            int cHash = 0;
            for (int j = 0; j < w; j++) {
                cHash *= cVal;
                cHash += c2i(eunPic[i][j]);
            }
            eunHash *= rVal;
            eunHash += cHash;
        }

        for (int i = 0; i < h - 1; i++) {
            rPow *= rVal;
        }
        for (int j = 0; j < w - 1; j++) {
            cPow *= cVal;
        }

        
        for (int i = 0; i < n; i++) {
            int _h = 0;
            for (int j = 0; j < w; j++) {
                _h *= cVal;
                _h += c2i(teaPic[i][j]);
            }
            tmp[i][0] = _h;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j + w <= m; j++) {
                int rm = cPow * c2i(teaPic[i][j - 1]);
                int add = c2i(teaPic[i][j + w - 1]);

                tmp[i][j] = tmp[i][j - 1] - rm;
                tmp[i][j] *= cVal;
                tmp[i][j] += add;
            }
        }

		for (int j = 0; j + w <= m; j++) {
            int _m = 0;
			for (int i = 0; i < h; i++) {
                _m *= rVal;
                _m += tmp[i][j];
            }
            tmp2[0][j] = _m;//todo: match eunHash
        }

		for (int j = 0; j + w <= m; j++) {
			for (int i = 1; i + h <= n; i++) {
                int rm = rPow * tmp[i - 1][j];
                int add = tmp[i + h - 1][j];

                tmp2[i][j] = tmp2[i - 1][j] - rm;
                tmp2[i][j] *= rVal;
                tmp2[i][j] += add;
            }
        }

        for (int i = 0; i + h <= n; i++) {
            for (int j = 0; j + w <= m; j++) {
                if (tmp2[i][j] == eunHash) {
                    answer++;
                }
            }
        }

        cout << '#' << tc << ' ' << answer << '\n';
        
    }

    return 0;
}

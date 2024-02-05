#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;



vector<string> board;
int n, m;
set<string> repo;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ) {
            int z = j;
            string str;
            while (z < m and board[i][z] != '#') {
                str.push_back(board[i][z]);
                z++;
            }
            if (str.size() >= 2) {
                repo.insert(str);
            }
            j = z + 1;
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n;) {

            int z = i;
            string str;
            while (z < n and board[z][j] != '#') {
                str.push_back(board[z][j]);
                z++;
            }
            if (str.size() >= 2) {
                repo.insert(str);
            }
            i = z + 1;
        }
    }

    cout << *repo.begin();
    



}

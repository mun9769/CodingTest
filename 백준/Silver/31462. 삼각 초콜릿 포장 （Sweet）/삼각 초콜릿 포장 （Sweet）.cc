
#include <bits/stdc++.h>
        using namespace std;

    using ll = long long;

    int n;

    char board[5005][5005];
    bool chk[5005][5005];


    int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin >> n;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                board[i][j] = s[j];
            }
        }
        bool ans = true;

        for (int i = 0; i < n; i++) {
            if (ans == false)
                break;
            for (int j = 0; j < i + 1; j++) {
                if (chk[i][j])
                    continue;
                if (i == n - 1) {
                    ans = false;
                    break;
                }

                if (board[i][j] == 'B') {
                    if (j == i) {
                        ans = false;
                        break;
                    }

                    if (board[i][j + 1] != 'B' || board[i + 1][j + 1] != 'B' || chk[i][j+1] || chk[i+1][j+1]) {
                        ans = false;
                        break;
                    }

                    chk[i][j] = true;
                    chk[i][j + 1] = true;
                    chk[i + 1][j + 1] = true;
                }
                else if (board[i][j] == 'R') {

                    if (board[i + 1][j] != 'R' || board[i + 1][j + 1] != 'R' || chk[i+1][j] || chk[i+1][j+1]) {
                        ans = false;
                        break;
                    }

                    chk[i][j] = true;
                    chk[i + 1][j] = true;
                    chk[i + 1][j + 1] = true;
                }
            }
        }
        if (ans)
            cout << '1';
        else
            cout << '0';

        return 0;
    }

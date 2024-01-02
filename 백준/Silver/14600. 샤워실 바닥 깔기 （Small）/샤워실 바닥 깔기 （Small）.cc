#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define mod 1'000'000'009



int k;
int board[6][6];
int x, y;

int region[6][6] = {
        {},
        {0, 1, 1, 2, 2},
        {0, 1, 1, 2, 2},
        {0, 5, 5, 6, 6},
        {0, 5, 5, 6, 6},
};

int main() {
    cin >> k;
    cin >> x >> y;

    if(k == 1) {
        for(int i=2; i>=1; i--) {
            for(int j=1; j<=2; j++) {
                if(j == x and i == y) cout << "-1 ";
                else cout << "1 ";
            }
            cout << endl;
        }
        return 0;
    }

    board[x][y] = -1;

    if(2 <= x and x <= 3 and 2 <= y and y <= 3) {
        for(int i=2; i<=3; i++) {
            for(int j=2; j<=3; j++) {
                if(board[i][j] != -1) board[i][j] = 1;
            }
        }
        board[1][1] = board[2][1] = board[1][2] = 2;
        board[4][1] = board[3][1] = board[4][2] = 3;
        board[1][4] = board[1][3] = board[2][4] = 4;
        board[4][4] = board[4][3] = board[3][4] = 5;
    }

    else {
        int mini[5][5];
        int a = x % 2 == 0 ? 2 : 1;
        int b = y % 2 == 0 ? 2 : 1;
        mini[a][b] = -1;
        for(int i=1; i<=2; i++) {
            for(int j=1; j<=2 ;j++) {
                if(mini[i][j] != -1) mini[i][j] = 1;
            }
        }

        vector<ii> offsets = {
                {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,-1}, {-1,1},
        };
        for(auto offset: offsets) {
            int nx = x + offset.first;
            int ny = y + offset.second;
            if(region[nx][ny] == region[x][y]) {
                board[nx][ny] = 1;
            }
        }

        if(board[1][1] == 0) board[1][1] = board[2][1] = board[1][2] = 2;
        if(board[4][1] == 0) board[4][1] = board[3][1] = board[4][2] = 3;
        if(board[1][4] == 0) board[1][4] = board[1][3] = board[2][4] = 4;
        if(board[4][4] == 0) board[4][4] = board[4][3] = board[3][4] = 5;

        for(int i=2; i<=3; i++) {
            for(int j=2; j<=3; j++) {
                if(board[i][j] == 0) board[i][j] = 6;
            }
        }
    }

    for(int j=4; j>=1; j--) {
        for(int i=1; i<=4; i++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }


}

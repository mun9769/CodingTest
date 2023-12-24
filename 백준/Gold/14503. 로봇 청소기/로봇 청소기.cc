#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


enum Dir {
    north = 0, east = 1, south = 2, west = 3,
};
enum tile {

    dirty = 0, wall = 1, clean
};
int n, m;
int d;
Dir dir;

int r, c;
tile board[55][55];

int answer;

ii offsets(Dir d) {
    if(d == north) return {-1, 0};
    if(d == east) return {0, 1};
    if(d == south) return {1, 0};
    if(d == west) return {0, -1};

    throw std::logic_error("");
}

Dir operator-(Dir& lhs, int x) {
    int result = ( static_cast<int>(lhs) - x + sizeof(Dir) ) % sizeof(Dir);

    return static_cast<Dir>(result);
}

bool found_dirty() {
    Dir nxt_dir = dir;
    for(int i=0; i<4; i++) {
        nxt_dir = nxt_dir - 1;
        int nx = r + offsets(nxt_dir).first;
        int ny = c + offsets(nxt_dir).second;

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        if(board[nx][ny] == tile::dirty) {
            dir = nxt_dir;
            r = nx; c = ny;
            return true;
        }
    }

    return false;
}

bool can_go_backword() {

    Dir back = dir - 2;

    int nx = r + offsets(back).first;
    int ny = c + offsets(back).second;

    if(nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
    if(board[nx][ny] == tile::wall) return false;

    r = nx; c = ny;
    return true;
}


int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    dir = static_cast<Dir>(d);
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        int a;
        cin >> a;
        board[i][j] = static_cast<tile>(a);
    }


    while(true) {
        if(board[r][c] == tile::dirty) {
            board[r][c] = tile::clean;
            answer++;
        }

        if(found_dirty()) {
            // TODO
            // 이미 로봇이 움직임.
        }
        else {
            if(can_go_backword()) {
                // TODO
                // 이미 로봇이 움직임.
            }
            else {
                break;
            }
        }
    }
    cout << answer;

}

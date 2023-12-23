#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n, k, l;
vector<ii> command;
// 1은 오른쪽, 2는 왼쪽
vector<ii> offsets = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
};

enum tile {
    none, apple, body
};

tile board[105][105];

struct Body {
    Body* prv = nullptr;
    Body* nxt = nullptr;
    int first;
    int second;

    Body(int _first, int _second) {
        first = _first;
        second = _second;
    }

};

class snake {
public:
    int dir = 0;
    // 0: 오른쪽 // 1: 아래 // 2: 왼쪽 // 3: 위
    Body* head;
    Body* tail;

    snake() {
        Body* adam = new Body(1, 1);
        head = adam;
        tail = adam;
    }

    bool go() {
        int nx = head->first + offsets[dir].first;
        int ny = head->second + offsets[dir].second;

        if(nx < 1 || ny < 1 || nx > n || ny > n) return false;
        if(board[nx][ny] == tile::body) return false;

        else if(board[nx][ny] == tile::apple) {
            head_move_forward(nx, ny);
        }
        else if(board[nx][ny] == tile::none) {
            head_move_forward(nx, ny);

            tail_move_forward();
        }

        return true;
    }

    void head_move_forward(int nx, int ny) {
        Body* new_head = new Body(nx, ny);
        new_head->prv = head;
        head->nxt = new_head;
        head = new_head;
        board[nx][ny] = tile::body;
    }

    void tail_move_forward() {
        if(tail->nxt == nullptr) throw std::logic_error("");

        Body* nxt_tail = tail->nxt;
        nxt_tail->prv = nullptr;
        board[tail->first][tail->second] = tile::none;
        delete tail;

        tail = nxt_tail;
    }

    void rotate_dir(int turn) {
        dir = (dir + turn + 4) % 4;
    }
};




int main() {
    cin >> n >> k;
    board[1][1] = tile::body;

    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        board[a][b] = tile::apple;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int a;
        char c;
        cin >> a >> c;
        if(c == 'D') command.push_back({a, 1});
        else command.push_back({a, -1});
    }

    snake s = snake();

    int idx = 0;
    int ans = 0;
    while(s.go()) {
        ans++;

        if(idx == command.size()) continue;

        auto [t, turn] = command[idx];
        if(ans == t) {
            idx++;
            s.rotate_dir(turn);
        }
    }
    ans++;
    cout << ans;
    return 0;
}

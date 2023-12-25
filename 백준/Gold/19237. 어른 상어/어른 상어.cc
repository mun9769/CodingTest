#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
#define sz 22

enum Dir {
    upward = 1, downward = 2, leftward = 3, rightward = 4,
};

int n, m, k;
ii board[sz][sz]; // {id, k}
vector<int> reserve_board[sz][sz];
int alive_shark_amount;

ii offset(Dir d) {
    if(d == upward) return {-1, 0};
    if(d == downward) return {1, 0};
    if(d == leftward) return {0, -1};
    if(d == rightward) return {0, 1};

    throw std::logic_error("");
}

class Shark {
public:
    int id;
    ii pos;
    Dir dir;
    bool alive = true;
    map<Dir, vector<Dir>> priority_direct;

    void reserve_my_position() {
        ii nxt = find_no_smell_position();

        if(nxt == make_pair(-1, -1)) { // 안냄새나는곳이 없을 때
            nxt = find_trace();
        }

        reserve_board[nxt.first][nxt.second].push_back(id);
    }

    void dead() {
        alive_shark_amount--;
        this->alive = false;
    }

    ii find_no_smell_position() {
        vector<Dir>& pd = priority_direct[this->dir];
        for(Dir nxt_dir: pd) {
            int nx = pos.first + offset(nxt_dir).first;
            int ny = pos.second + offset(nxt_dir).second;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny].second > 0) continue;

            dir = nxt_dir;
            return {nx, ny};
        }

        return {-1, -1};
    }

    ii find_trace() {
        vector<Dir>& pd = priority_direct[this->dir];
        for(Dir nxt_dir: pd) {
            int nx = pos.first + offset(nxt_dir).first;
            int ny = pos.second + offset(nxt_dir).second;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny].first != this->id) continue;

            dir = nxt_dir;
            return {nx, ny};
        }

        throw std::logic_error("trace가 주위에 꼭 있어야함");
    }

    void set_priority_direction() {
        for(int i=1; i<=4; i++) for(int j=1; j<=4; j++)  {
            Dir watch_dir = static_cast<Dir>(i);
            int i32dir;
            cin >> i32dir;
            priority_direct[watch_dir].push_back(static_cast<Dir>(i32dir));
        }
    }
};




Shark sharks[403];

void setup() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        cin >> board[i][j].first;
        if(board[i][j].first > 0) {
            int id = board[i][j].first;
            board[i][j].second = k;
            sharks[id].pos = {i, j};
        }
    }
    for(int i=1; i<=m; i++) {
        int i32_dir;
        cin >> i32_dir; // scanf는 enum을 입력받을 수 있나?
        sharks[i].dir = static_cast<Dir>(i32_dir);
        sharks[i].id = i;
    }

    for(int i=1; i<=m; i++) sharks[i].set_priority_direction();

    alive_shark_amount = m;
}

void move_sharks() {
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        vector<int>& candidate = reserve_board[i][j];

        for(int x=0; x<candidate.size(); x++) {
            int id = candidate[x];
            if(x == 0) {
                board[i][j] = {id, k + 1}; // board의 모든 셀의 k를 1 줄일거라 1을 더해줌
                sharks[id].pos = {i, j};
            }
            else
                sharks[id].dead();
        }

        reserve_board[i][j].clear();
    }
}

void smell_minus_one() {
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
            if(board[i][j].second == 1) {
                board[i][j] = {0, 0};
            }
            else if(board[i][j].second > 1) {
                board[i][j].second--;
            }
    }
}

void reserve_alive_sharks() {
    for(int i=1; i<=m; i++) {
        if(sharks[i].alive == false) continue;
        sharks[i].reserve_my_position();
    }
}


int main() {
    setup();

    int timer = 0;
    while(timer < 1001) {
        reserve_alive_sharks();

        move_sharks();

        smell_minus_one();

        timer++;

        if(alive_shark_amount == 1) break;
    }

    if(timer == 1001) cout << -1;
    else cout << timer;
}

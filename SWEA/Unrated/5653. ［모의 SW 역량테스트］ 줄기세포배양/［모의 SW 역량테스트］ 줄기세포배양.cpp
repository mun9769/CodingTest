#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

enum CellState {
    dead, alive, count
};
vector<ii> offsets = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
};

vector<int> expandTask[303];
vector<int> dieTask[303];

struct cell {
    int id = -1;
    int life;
    ii pos;

    cell(int b, ii c, int d): life(b), pos(c) {}
    cell() {}

    void operator=(const cell& rhs) { // 어떻게 createdAt을 넣어줄 수 있을까?
       life = rhs.life;
       pos = rhs.pos;

       id = cell::cellId++;
       cell::aliveCount++;
    }

    void bookTask(int createdAt) { // 할당할 때 호출하고 싶은데 할당 연산자에서 내가 원하는 변수를 입력할 수 없음.
        dieTask[createdAt + life*2].push_back(this->id);
        expandTask[createdAt + life + 1].push_back(this->id);
    }
    // copy assignment?
    static int aliveCount; // destructor?
    static int cellId;

    void die() {
        aliveCount--;
    }

};

cell pool[1'000'000];
int board[450][450];

// todo: life + 1 시간 후에 번식
// todo: lift * 2 시간 후에 죽음


// function<int> tasks[303]; // TODO: does an awesome way exist using std::function?

int cell::aliveCount = 0; // it should be written "int"?
int cell::cellId = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample_input.txt", "r",stdin);
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++) {
        cell::aliveCount = 0;
        cell::cellId = 1;
        for(int i=0; i<302; i++){
            dieTask[i].clear();
            expandTask[i].clear();
        }
        for(int i=0; i<450; i++) {
            for(int j=0; j<450; j++) {
                board[i][j] = 0;
            }
        }
        int n, m, k;
        cin >> n >> m >> k;

        for(int i=0 ;i<n; i++) {
            for (int j = 0; j < m; j++) {
                int life;
                cin >> life;
                if(life != 0) {
                    cell& newCell = pool[cell::cellId];
                    board[200 + i][200 + j] = cell::cellId;

                    newCell = { life, {200 + i, 200 + j}, 0 };
                    newCell.bookTask(0);
                    // it needs copy assignment(within const-rhs) and handmade construction;

                }
            }
        }

        for(int time=1; time<=k; time++) {
            map<ii, int> tmp;

            for(auto id: expandTask[time]) {
                auto [x, y] = pool[id].pos;

                for(auto [dx, dy]: offsets) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // log: 43 minutes //6:32
                    if(board[nx][ny] == 0) {
                        auto iter = tmp.find({nx, ny});
                        if(iter == tmp.end()) { // not exist
                            tmp[{nx, ny}] = id;
                        } else {
                            int compareToLife = pool[iter->second].life;
                            if(compareToLife < pool[id].life) {
                                iter->second = id;
                            }
                        }
                    }
                }
            }
            for(auto [pos, id] :tmp) {
                cell& newCell = pool[cell::cellId];
                newCell = pool[id];
                newCell.pos = pos;
                board[pos.first][pos.second] = newCell.id;

                newCell.bookTask(time);
            }

            for(auto id: dieTask[time]) {
                pool[id].die();
            }
        }

        cout << '#'<<tc<<' ';
        cout << cell::aliveCount << '\n';

    }

}

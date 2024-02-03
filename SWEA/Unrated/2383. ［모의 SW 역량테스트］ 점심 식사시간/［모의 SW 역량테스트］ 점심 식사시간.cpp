#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n;
int board[14][14];
int dist[10][2];
vector<ii> pos;
vector<ii> door;

int costTime[2];


int moveSimulation(vector<int>& zero, vector<int>& one) {
    int num = zero.size() + one.size();
    int goal = 0;
    int time = 0;
    multiset<int> ongoing0;
    multiset<int> ongoing1;
    queue<int> process0;
    queue<int> process1;
    queue<int> pending0;
    queue<int> pending1;

    for(auto id: zero) {
        ongoing0.insert(dist[id][0]);
    }
    for(auto id: one) {
        ongoing1.insert(dist[id][1]);
    }
    auto cur0 = ongoing0.begin();
    auto cur1 = ongoing1.begin();

    while(goal < num) {
        // 계단 내려가는 사람
        while(!process0.empty() and process0.front() == time) {
            process0.pop();
            goal++;
            if(!pending0.empty()) {
                pending0.pop();
                process0.push(time + costTime[0]);
            }
        }

        while(!process1.empty() and process1.front() == time) {
            process1.pop();
            goal++;
            if(!pending1.empty()) {
                pending1.pop();
                process1.push(time + costTime[1]);
            }
        }

        // 오는 사람
        while(cur0 != ongoing0.end() and *cur0 == time) {
            if(process0.size() < 3) {
                process0.push(time + costTime[0]+1);
            }
            else {
                pending0.push(0);
            }
            cur0++;
        }
        while(cur1 != ongoing1.end() and *cur1 == time) {
            if(process1.size() < 3) {
                process1.push(time + costTime[1]+1);
            }
            else {
                pending1.push(1);
            }
            cur1++;
        }

        time++;
    }

    return time - 1;

}

int main()
{ // 10:10
    cin.tie(0)->sync_with_stdio(0);
   // freopen("sample_input.txt", "r",stdin);
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++) {
        memset(dist, 0, sizeof(dist));
        int answer = INT32_MAX;
        pos.clear();
        door.clear();

        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                cin >> board[i][j];
                if(board[i][j] == 1) {
                    pos.push_back({i, j});
                }
                else if(board[i][j] != 0) {
                    door.push_back({i, j});
                }
            }
        }
        for(int i=0; i<2; i++) {
            auto& [x, y] = door[i];
            costTime[i] = board[x][y];
        }
        for(int i=0; i<pos.size(); i++) {
            auto [x, y] = pos[i];
            for(int j=0; j<2; j++) {
                auto [u, v] = door[j];
                dist[i][j] = abs(x - u) + abs(y - v);
            }
        }

        for(int i=0; i< (1<<pos.size()); i++) {
            vector<int> zero;
            vector<int> one;

            for(int id=0; id<pos.size(); id++) {
                if(i & (1 << id)) {
                    one.push_back(id);
                }
                else {
                    zero.push_back(id);
                }
            }

            int ret = moveSimulation(zero, one);
            answer = min(answer, ret);
        }
        cout << '#'<<tc<<' ';
        cout << answer << '\n';

    }

}

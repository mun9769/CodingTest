#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#define INF 987654321

using namespace std;

char map[11][11], copy_map[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void turn_on(int x, int y){ //불을 키고끄는 부분입니다.
    if(copy_map[x][y] == 'O') copy_map[x][y] = '#';
    else copy_map[x][y] = 'O';
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx >= 0 && xx < 10 && yy >= 0 && yy < 10){ // map에 범위에 맞는지 확인
            if(copy_map[xx][yy] == 'O') copy_map[xx][yy] = '#';
            else copy_map[xx][yy] = 'O';
        }
    }
}

void reset_map(){ // map을 복사한다.
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            copy_map[i][j] = map[i][j];
        }
    }
}

bool all_light_on(){ // 불이 전부 꺼져있으면 true 아니면 false를 return한다.
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(copy_map[i][j] == 'O') return false;
        }
    }
    return true;
}

void solve(){
    int ans = INF; // 최소 횟수 저장
    for(int step = 0; step < (1 << 10); step++){ // 첫째줄에 나올 수 있는 경우 모두 확인
        int cnt = 0;
        reset_map();
        for(int i = 0; i < 10; i++){ // 첫번째 줄에 불이 켜져있는 부분을 확인
            if(step & (1 << i)){
                cnt++;
                turn_on(0, i);
            }
        }
        for(int i = 1; i < 10; i++){ // 첫줄에 따라 2번째 줄부터 어떤 곳을 꺼야하는지 확인
            for(int j = 0; j < 10; j++){
                if(copy_map[i-1][j] == 'O'){
                    turn_on(i, j);
                    cnt++;
                }
            }
        }
        if(all_light_on()) ans = min(ans, cnt);
    }
    if(ans == INF) cout << "-1";
    else cout << ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}
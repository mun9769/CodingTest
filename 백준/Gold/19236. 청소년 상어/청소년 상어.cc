//
//  main.cpp
//  test
//
//  Created by moon on 2023/09/11.
//

#include <iostream>
#include <vector>
using namespace std;
#define ii pair<int, int>

vector<vector<ii>> board(4); // { id, dir }
int ans;

bool canGo(int nx, int ny){
    if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return false;
    if(board[nx][ny].first == 99) return false;
    return true;
}

ii fishManager[18]; // id -> x, y

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};


ii rotate(int x, int y) {
    int id = board[x][y].first;
    int dir = board[x][y].second;
    
    for(int i=0; i<8; i++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(canGo(nx, ny) == false) {
            dir++;
            dir %= 8;
            continue;
        }
        break;
    }
    board[x][y].second = dir;
    return {x + dx[dir], y + dy[dir]};
}

void move() {
    for(int i=1; i<=16; i++){
        int id = i;
        int x = fishManager[id].first;
        int y = fishManager[id].second;
        if(x == -1) continue;
        
        auto [nx, ny] = rotate(x, y);
        
        int countId = board[nx][ny].first;
        
        swap(board[x][y], board[nx][ny]);
        if(countId != -1) swap(fishManager[id], fishManager[countId]);
        else fishManager[id] = {nx, ny};
        
    }
}

void eat(int x, int y, int nx, int ny) {
    board[x][y].first = -1;
    int id = board[nx][ny].first;
    fishManager[id] = {-1, -1};
    ans += id;
    board[nx][ny] = {99, board[nx][ny].second};
}

bool canGoShark(int nx, int ny) {
    if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) return false;
    if(board[nx][ny].first == -1) return false;
    if(board[nx][ny].first == 99) return false;
    
    return true;
}

void rollback(int x, int y, int id, int dir){
    ans -= id;
    fishManager[id] = {x, y};
}

int answer;


void dfs(int x, int y, int dep) {
    
    if(answer < ans) {
        answer = ans;
    }
    vector<vector<ii>> repo = board;
    ii repoManager[18];
    
    for(int i=1; i<=16; i++){
        repoManager[i] = fishManager[i];
    }
    
    
    
    int dir = board[x][y].second;
    
    int nx = x;
    int ny = y;
    
    for(int i=0; i<3; i++){
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        if(canGoShark(nx, ny) == false) continue;
        
        int id = board[nx][ny].first;
        
        eat(x, y, nx, ny);
        move();
        
        dfs(nx, ny, dep + 1);
        
        board = repo;
        for(int i=1; i<=16; i++) fishManager[i] = repoManager[i];
        ans -= id;
        
    }
}


int main(int argc, const char * argv[]) {
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int id, dir;
            cin >> id >> dir;
            fishManager[id] = {i, j};
            board[i].push_back({id, dir-1});
        }
    }
    
    
    int id = board[0][0].first;
    ans += id;
    board[0][0].first = 99;
    fishManager[id] = {-1, -1};
    
    move();
    dfs(0, 0, 1);
    
    cout << answer;
    
}

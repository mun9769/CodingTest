#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;


int o_cnt = 0;
int x_cnt = 0;
int dot_cnt = 0;

bool playerWin(vector<string>& board, char stone) {
    
    for(int x=0; x<3; x++){
        char row = board[x][0];
        char col = board[0][x];
        
        int row_cnt = 0;
        int col_cnt = 0;
        for(int y=0; y<3; y++){
            if(row == stone and board[x][y] == row) row_cnt++;
            if(col == stone and board[y][x] == col) col_cnt++;
        }
        
        if(row_cnt == 3) { return true; }
        if(col_cnt == 3) { return true; }
    }
    
    if(board[0][0] == stone &&
      board[0][0] == board[1][1] && 
      board[0][0] == board[2][2]) return true;
    
    if(board[0][2] == stone &&
      board[0][2] == board[1][1] && 
      board[0][2] == board[2][0]) return true;
    
    
    return false;
}

bool check_incorrect_count(vector<string>& board) {
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == 'O') o_cnt++;
            else if(board[i][j] == 'X') x_cnt++;
            else if(board[i][j] == '.') dot_cnt++;
        }
    }
    
    
    if(o_cnt > x_cnt + 1 || o_cnt < x_cnt) return true;
    
    return false;
    
}

int solution(vector<string> board) {
    if(check_incorrect_count(board))
        return 0;
    
    if(playerWin(board, 'O') and o_cnt - x_cnt != 1)
        return 0;
    
    if(playerWin(board, 'X') and o_cnt - x_cnt != 0)
        return 0;
    
    if(playerWin(board, 'O') and playerWin(board, 'X'))
        return 0;
    
    return 1;
}


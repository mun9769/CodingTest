#include <string>
#include <vector>

using namespace std;

const int dh[] = {1,0,-1,0};
const int dw[] = {0,1,0,-1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    for(int i=0; i<4; i++){
        int nh = h + dh[i];
        int nw = w + dw[i];
        
        if(nh < 0 || nw < 0 || nh >= board.size() || nw >= board[0].size()) 
            continue;
        
        if(board[nh][nw] == board[h][w]) 
            answer++;
    }
    
    
    
    return answer;
}
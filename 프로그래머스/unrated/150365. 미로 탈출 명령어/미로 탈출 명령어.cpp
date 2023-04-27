#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int wait[4];

int _n, _m;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const char puz[] = {'d', 'l', 'r', 'u'};

bool canGo(int nx, int ny){
    if(nx < 1 || ny < 1 || nx > _n || ny > _m) return false;
    return true;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    _n = n;
    _m = m;
    string answer = "";
    // 올바른 길 구하기
    if(r > x) wait[0] = abs(r - x); // down
    else wait[3] = abs(r - x); // up
    
    if(c > y) wait[2] = abs(c - y); // right
    else wait[1] = abs(c - y); // left
    
    int nk = k - abs(r - x) - abs(c - y);
    
    if(nk < 0 || nk % 2 == 1) return "impossible";
    
    int i;
    for(i=k; i>0; i--){
        if(i == abs(r-x) + abs(c - y)){
            break;
        }
        for(int j=0; j<4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(canGo(nx, ny)){
                answer.push_back(puz[j]);
                x = nx; y = ny;
                break;
            }
        }
    }
    
    if(r > x) // down
        for(int i=0; i< r-x; i++)
            answer.push_back(puz[0]);
    if(c < y) // left
        for(int i=0; i< abs(y-c); i++)
            answer.push_back(puz[1]);
    if(c > y)
        for(int i=0; i< abs(c-y); i++)
            answer.push_back(puz[2]);
    if(r < x)
        for(int i=0; i<abs(r-x); i++)
            answer.push_back(puz[3]);
    
    
    
    return answer;
}
#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

ii pos;

int c2i(char c) {
    if(c == 'E') return 1;
    if(c == 'W') return 3;
    if(c == 'S') return 0;
    if(c == 'N') return 2;
    
    return -1;
}
vector<string> park;
int n, m;
bool canGo(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    if(park[x][y] == 'X') return false;
    return true;
}

vector<int> solution(vector<string> _park, vector<string> routes) {
    vector<int> answer;
    park = _park;
    n = park.size();
    m = park[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(park[i][j] == 'S') pos = {i, j};
        }
    }
    
    for(auto route: routes) {
        char dir = route[0];
        char times = route[2];
        int d = c2i(dir);
        int num = times - '0';
        
        bool possible = true;
        for(int i=1; i<=num; i++) {
            int nx = pos.first + dx[d] * i;
            int ny = pos.second + dy[d] * i;
            if(canGo(nx, ny) == false)  {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            pos.first += dx[d] * num;
            pos.second += dy[d] * num;
        }
        
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    
    return answer;
}
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<string> maps;
int visited[104][104];
int n, m;

vector<ii> offsets = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

ii operator+(ii& lhs, ii& rhs) {
    int x = lhs.first + rhs.first;
    int y = lhs.second + rhs.second;
    
    return {x, y};
}

bool canGo(ii nxt) {
    auto [nx, ny] = nxt;
    if(nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
    if(maps[nx][ny] == 'X') return false;
    if(visited[nx][ny] == 1) return false;
    
    return true;
}

int recursive(ii cur) {
    auto [x, y] = cur;
    
    visited[x][y] = 1;
    int sum = maps[x][y] - '0';
    
    for(auto offset: offsets) {
        ii nxt = cur + offset;
        if(canGo(nxt)) {
            sum += recursive(nxt);
        }
    }
    return sum;
}

vector<int> solution(vector<string> _maps) {
    vector<int> answer;
    maps = _maps;
    n = maps.size();
    m = maps[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(canGo({i, j})) {
                int meal = recursive({i, j});
                answer.push_back(meal);
            }
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}
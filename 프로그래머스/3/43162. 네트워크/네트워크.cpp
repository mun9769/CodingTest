#include <string>
#include <vector>

using namespace std;
vector<vector<int>> computers;
int n;
bool visited[203];

bool canGo(int x) {
    if(visited[x]) return false;
    
    return true;
}

void dfs(int cur) {
    visited[cur] = true;
    
    for(int nxt=0; nxt<n; nxt++){
        if(computers[cur][nxt] and canGo(nxt)) {
            dfs(nxt);
        } 
    }
}

int solution(int _n, vector<vector<int>> _computers) {
    int answer = 0;
    computers = _computers;
    n = _n;
    for(int i=0; i<n; i++){
        if(visited[i] == false) {
            dfs(i);
            answer++;
        }
    }
    return answer;
}
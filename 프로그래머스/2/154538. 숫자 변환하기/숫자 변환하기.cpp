#include <bits/stdc++.h>
using namespace std;

int x, y, n;
int visited[1'000'005];

queue<int> q;

void go(int cur, int nxt) {
    if(nxt > 1'000'000) return;
    if(visited[nxt] == -1) {
        visited[nxt] = visited[cur] + 1;
        q.push(nxt);
    }
}

void bfs() {
    
    q.push(x);
    visited[x] = 0;
    while(q.size()) {
        int cur = q.front();
        q.pop();
        go(cur, cur + n);
        go(cur, cur * 2);
        go(cur, cur * 3);
    }
}


int solution(int _x, int _y, int _n) {
    int answer = 0;
    x = _x;
    y = _y;
    n = _n;
    fill(visited, visited + 1'000'003, -1);
    
    bfs();
    
    return visited[y];
}
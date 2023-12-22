#include <bits/stdc++.h>
using namespace std;

int dp[10][10][100'003];
int n;
string numbers;

map<int, vector<int>> weight = {
    { 0, {1, 7, 6, 7, 5, 4, 5, 3, 2, 3} },
    { 1, {7, 1, 2, 4, 2, 3, 5, 4, 5, 6} },
    { 2, {6, 2, 1, 2, 3, 2, 3, 5, 4, 5} },
    { 3, {7, 4, 2, 1, 5, 3, 2, 6, 5, 4} },
    { 4, {5, 2, 3, 5, 1, 2, 4, 2, 3, 5} },
    
    { 5, {4, 3, 2, 3, 2, 1, 2, 3, 2, 3} },
    { 6, {5, 5, 3, 2, 4, 2, 1, 5, 3, 2} },
    { 7, {3, 4, 5, 6, 2, 3, 5, 1, 2, 4} },
    { 8, {2, 5, 4, 5, 3, 2, 3, 2, 1, 2} },
    { 9, {3, 6, 5, 4, 5, 3, 2, 4, 2, 1} },
    //    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};


int recur(int x, int y, int idx) {
    int target = numbers[idx] - '0';
    
    if(idx == numbers.size()) return 0;
    if(dp[x][y][idx] != 0) return dp[x][y][idx];
    
    int nx = INT32_MAX;
    int ny = INT32_MAX;
    
    if(target != y) {
        nx = recur(target, y, idx+1) + weight[x][target];
    }
    
    if(target != x) {
        ny = recur(x, target, idx+1) + weight[y][target];
    }
    
    return dp[x][y][idx] = min(nx, ny);
    
}

int solution(string _numbers) {
    int answer = 0;
    numbers = _numbers;
    answer = recur(4, 6, 0);
    
    return answer;
}
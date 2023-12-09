#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int m, n;
ii pos;
ii desired;
int output;

void calc_module(int x1, int y1, int x2, int y2, int m) {
    if(y1 == y2) {
        if(x1 > x2) {
            int k = pow(m - x1 + m - x2, 2);
            output = min(output, k);
        }
        else{
            int k = pow(x1 + x2, 2);
            output = min(output, k);
        }
        return;
    }
    
    int a = x1 + x2;
    int b = abs(y1 - y2);
    
    output = min(output, a * a + b * b);
}

void calc_len() {
    auto [x1, y1] = pos;
    auto [x2, y2] = desired;
    
    calc_module(x1, y1, x2, y2, m);
    calc_module(m - x1, y1, m - x2, y2, m);
    
    calc_module(y1, x1, y2, x2, n);
    calc_module(n - y1, x1, n - y2, x2, n);
    
}

vector<int> solution(int _m, int _n, int startX, int startY, vector<vector<int>> balls) {
    m = _m;
    n = _n;
    vector<int> answer;
    
    pos = {startX, startY};
    
    for(vector<int> ball: balls) {
        desired = {ball[0], ball[1]};
        output = INT32_MAX;
        calc_len();
        
        answer.push_back(output);
    }
    
    return answer;
}
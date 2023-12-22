#include <bits/stdc++.h>
using namespace std;

int col;
bool pred(vector<int>& a, vector<int>& b) {
    if(a[col] == b[col]) {
        return a[0] > b[0];
    }
    return a[col] < b[col];
}

int solution(vector<vector<int>> data, int _col, int row_begin, int row_end) {
    int answer = 0;
    col = _col-1;
    sort(data.begin(), data.end(), pred);
    
    
    vector<int> s_i;
    for(int i=row_begin; i<=row_end; i++) {
        int sum = 0;
        
        for(auto x: data[i-1]) {
            sum += x % i;
        }
        s_i.push_back(sum);
        
    }
    
    for(auto x: s_i) {
        answer = answer ^ x;
    }
    
    return answer;
}
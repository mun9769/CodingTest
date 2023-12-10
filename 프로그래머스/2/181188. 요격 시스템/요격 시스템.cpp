#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end());
    
    int preStart = targets[0][0];
    int preEnd = targets[0][1];
    
    for(int i=1; i<targets.size(); i++){
        
        int curStart = targets[i][0];
        int curEnd = targets[i][1];
        
        if(curStart < preEnd) {
            preStart = max(preStart, curStart);
            preEnd = min(preEnd, curEnd);
        }
        else {
            answer++;
            preStart = curStart;
            preEnd = curEnd;
        }
        
    }
    answer++;
    
    return answer;
}
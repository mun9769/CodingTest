#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    sort(attacks.begin(), attacks.end());
    int cur = 0;
    int accumulatedTime = 0;
    
    int hp = health;
    int finalTime = (*attacks.rbegin())[0];
    for(int time = 0; time<=finalTime; time++) {
        
        if(cur < attacks.size() and attacks[cur][0] == time) {
            hp -= attacks[cur][1];
            cur++;
            accumulatedTime = 0;
            if(hp <= 0) break;
            continue;
        }
        
        accumulatedTime++;
        if(accumulatedTime == t) {
            hp = hp + y;
            accumulatedTime = 0;
        }
        hp = hp + x;
        hp = min(health, hp);
        
    }
    
    if(hp <= 0) answer = -1;
    else answer = hp;
    
    return answer;
}
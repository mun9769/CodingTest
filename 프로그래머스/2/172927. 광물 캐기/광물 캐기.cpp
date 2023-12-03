#include <bits/stdc++.h>
using namespace std;

vector<int> picks;
vector<string> minerals;

void filter_picks() {
    int need = (minerals.size()-1) / 5 + 1;
    int inven = accumulate(picks.begin(), picks.end(), 0);
    int gap = inven - need;
    
    if(gap > 0) { // 필요없는 stone 빼기
        int item = min(gap, picks[2]);
        gap -= item;
        picks[2] -= item;
    }
    if(gap > 0) { // 필요없는 iron 빼기
        int item = min(gap, picks[1]);
        gap -= item;
        picks[1] -= item;
    }
    if(gap > 0) {
        picks[0] -= gap;
    }
}
int ans = INT32_MAX;

int get_pick(int id) {
    if(id < picks[0]) return 0;
    if(id < picks[1] + picks[0]) return 1;
    if(id < picks[2] + picks[1] + picks[0]) return 2;
    return -1;
}

int calc_tired(int pick, string name) {
    if(pick == 0) {
        return 1;
    }
    else if(pick == 1) {
        if(name == "diamond") return 5;
        return 1;
    }
    else if(pick == 2) {
        if(name == "diamond") return 25;
        else if(name == "iron") return 5;
        return 1;
    }
}

int solution(vector<int> _picks, vector<string> _minerals) {
    int answer = 0;
    picks = _picks;
    minerals = _minerals;
    filter_picks();

    int dia = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    vector<int> v;
    
    for(int i=0; i<dia + iron + stone; i++){
        v.push_back(i);
    }
    
    do {
        int sum = 0;
        for(int i=0; i<minerals.size() and i / 5 < dia + iron + stone;) {
            int id = v[i / 5];
            int pick = get_pick(id);
            if(pick == -1) break;
            
            int cycle = 5;
            while(i < minerals.size() and cycle-- > 0) {
                string name = minerals[i];
                int tired = calc_tired(pick, name);
                sum += tired;
                
                i++;
            }
        }
        ans = min(ans, sum);
    } while(next_permutation(v.begin(),v.end()));
    
    answer = ans;
    
    return answer;
}
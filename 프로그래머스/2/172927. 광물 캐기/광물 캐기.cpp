#include <bits/stdc++.h>
using namespace std;

vector<int> picks;
vector<string> minerals;

int tired[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}};

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
int name2num(string name) {
    if(name == "diamond") return 0;
    if(name == "iron") return 1;
    if(name == "stone") return 2;
    return -1;
}

int calc(int pick, int index) {
    int sum = 0;
    for(int i=index; i < minerals.size() and i<index + 5; i++) {
        int num = name2num(minerals[i]);
        sum += tired[pick][num];
    }
    return sum;
}

int dfs(int a, int b, int c, int index) {
    if(a + b + c == 0 || index >= minerals.size()) return 0;
    
    int ret = INT32_MAX;
    if(a) ret = min(ret, calc(0, index) + dfs(a-1, b, c, index+5));
    if(b) ret = min(ret, calc(1, index) + dfs(a, b-1, c, index+5));
    if(c) ret = min(ret, calc(2, index) + dfs(a, b, c-1, index+5));
    
    return ret;
}


int solution(vector<int> _picks, vector<string> _minerals) {
    int answer = 0;
    picks = _picks;
    minerals = _minerals;
    filter_picks();

    int dia = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    
    answer = dfs(dia, iron, stone, 0);
    
    return answer;
}
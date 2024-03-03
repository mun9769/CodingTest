#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
int _n;
vector<int> _cards;
bool _hands[1032];
bool _repo[1032];
int _coin;
int ans;

void dfs(int turn) {
    ans = turn;
    if(_n/3 + (turn-1)*2 >= _n) {
        return;
    }
    
    int lft = _cards[_n/3 + (turn-1)*2];
    int rht = _cards[_n/3 + (turn-1)*2 + 1];
    _repo[lft] = true;
    _repo[rht] = true;
    
    int a = -1, b = -1;
    for(int i=1; i<=_n/2; i++) {
        if(_hands[i] && _hands[_n+1-i]) {
            a = i;
            b = _n+1-i;
            break;
        }
    }
    
    if(a == -1 and _coin >= 1) {
        for(int i=1; i<=_n; i++) {
            if(_hands[i] && _repo[_n+1-i]) {
                a = i;
                b = _n+1-i;
                _coin -= 1;
                break;
            }
        }
    }
    
    if(a == -1 and _coin >= 2) {
        for(int i=1; i<=_n/2; i++) {
            if(_repo[i] && _repo[_n+1-i]) {
                a = i;
                b = _n+1-i;
                _coin -= 2;
                break;
            }
        }
    }
    
    if(a!= -1) {
        _hands[a] = false;
        _hands[b] = false;
        dfs(turn+1);
    }
    
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    _n = cards.size();
    _cards = cards;
    _coin = coin;
    for(int i=0; i<cards.size() / 3; i++) {
        _hands[cards[i]] = true;
    }
    
    dfs(1);
    answer = ans;
    return answer;
}

int main() {
    cout << solution(6, {1,6,1,6,1,6});
}
#include<bits/stdc++.h>
#include <string>
using namespace std;
using ii = pair<int, int>;

string msg, key;
char board[5][5];
bool vis[26];
pair<int, int> pos[26];
vector<string> v;

int main(int argc, char** argv)
{
    cin >> msg;
    cin >> key;
    vis['J'-'A'] = true;
    int cur = 0;
    for(auto c: key) {
        if(vis[c-'A'] == false) {
            vis[c-'A'] = true;
            board[cur/5][cur%5] = c;
            cur++;
        }
    }
    for(;cur < 25;) {
        for(int x=0; x<26; x++) { // todo: two pointer
            if(vis[x] == false) {
                vis[x] = true;
                board[cur/5][cur%5] = x + 'A';
                cur++;
                break;
            }
        }
    }
    
    assert(board[4][4] >= 'A' and board[4][4] <= 'Z');

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            pos[board[i][j] - 'A'] = {i, j};
        }
    }

    while(msg.size() >= 2) {
        string sub = msg.substr(0, 2);
        if(sub[0] == sub[1]) {
            if(sub[0] == 'X') {
                sub.pop_back();
                sub.push_back('Q');
            }
            else {
                sub.pop_back();
                sub.push_back('X');
            }
            msg.erase(0, 1);
        }
        else {
            msg.erase(0, 2);
        }
        v.push_back(sub);
    }
    if(msg.size()) {
        if(msg.size() == 1) msg.push_back('X');
        v.push_back(msg);
    }
    for(auto tv: v) {
        assert(tv.size() == 2);
        char x = tv[0];
        char y = tv[1];
        pair<int, int> pos1 = pos[x - 'A'];
        pair<int, int> pos2 = pos[y - 'A'];
        char nx = '!', ny = '!';
        
        if(pos1.first == pos2.first) {
            nx = board[pos1.first][(pos1.second + 1) % 5];
            ny = board[pos1.first][(pos2.second + 1) % 5];
        }
        else if(pos1.second == pos2.second) {
            nx = board[(pos1.first + 1) % 5][pos1.second];
            ny = board[(pos2.first + 1) % 5][pos2.second];
        } 
        else {
            nx = board[pos1.first][pos2.second];
            ny = board[pos2.first][pos1.second];
        }

        assert(nx != '!' and ny != '!');

        cout << nx << ny;
    }
   return 0;
}

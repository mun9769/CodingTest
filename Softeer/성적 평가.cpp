#include<bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

int n;
int score[4][100'005];
map<int, vector<int>, cmp> mm[4]; // score, ids

int ans[4][100'005];

int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            cin >> score[i][j];
        }
    }
    for(int j=0; j<n; j++) {
        for(int i=0; i<3; i++){
            score[3][j] += score[i][j];
        }
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++) {
            mm[i][score[i][j]].push_back(j);
        }
        int rank = 1;
        for(auto& [_, v]: mm[i]) {
            
            for(auto x: v) {
                ans[i][x] = rank;
            }
            rank += (int)v.size();
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
   return 0;
}

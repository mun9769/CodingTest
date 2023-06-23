//
//  main.cpp
//  cpp
//
//  Created by moon on 2023/06/20.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <tuple>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
using namespace std;


int n, m;
int ts;

int main() {
    init
    cin >> ts;
    while(ts-->0){
        string s;
        cin >> s;
        int seq = 0;
        int ans = 0;
        for(auto letter: s){
            if(letter == 'O') {
                seq++;
                ans += seq;
            }
            else {
                seq = 0;
            }
        }
        cout << ans << ' ';
    }
    
}

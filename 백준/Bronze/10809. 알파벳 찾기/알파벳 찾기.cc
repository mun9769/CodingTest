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



int cnt[30];
string s;

int main() {
    init
    cin >> s;
    fill(cnt, cnt+30, -1);
    
    for(int i=0; i<s.size(); i++){
        int k = s[i] - 'a';
        
        if(cnt[k] == -1) cnt[k] = i;
    }
    for(int i=0;i<26; i++) cout << cnt[i] << ' ';
   
}

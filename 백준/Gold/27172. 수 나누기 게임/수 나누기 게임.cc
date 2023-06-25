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
#include <stack>
#include <tuple>
#include <algorithm>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
using namespace std;


int n;


int arr[100'005];

int score[1'000'003];

bool card[1'000'003];






int main() {
    init
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        card[arr[i]] = true;
    }
    
    for(int i=0; i<n; i++){
        int cur = arr[i];
        
        for(int j=cur * 2; j <= 1'000'002; j += cur){
            if(card[j] == true){
                score[cur]++;
                score[j]--;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        cout << score[arr[i]] << ' ';
    }
    
}

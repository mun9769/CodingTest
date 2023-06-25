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
#include <numeric>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
using namespace std;



int main() {
    init
    
    int arr[4];
    for(int i=0; i<4; i++) cin >> arr[i];
    int pos[3];
    for(int i=0; i<3; i++) cin >> pos[i];
    int x = pos[0];
    
    bool possible = false;
    for(int i=0; i<4; i++){
        if(x == arr[i]) {
            cout<< i+1;
            possible = true;
        }
    }
    if(possible == false){
        cout << 0 ;
    }
        
}

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



int n, x;

int main() {
    init
    cin >> n >> x;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a < x) cout << a << ' ';
    }
   
}

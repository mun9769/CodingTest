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

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define INF 1e9
using namespace std;

int n;
int dist[22][22];
bool chk[22][22];


int main() {
    init;
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> dist[i][j];
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                if(k == i) continue;
                if(k == j) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << -1;
                    return 0;
                }
                
                if(dist[i][j] == dist[i][k] + dist[k][j]){
                    chk[i][j] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(chk[i][j] == false) ans+= dist[i][j];
        }
    }
    
    cout << ans / 2;
    
    
    return 0;
}

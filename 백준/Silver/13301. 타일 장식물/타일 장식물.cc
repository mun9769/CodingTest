

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
#define ll long long
using namespace std;


int n;
ll fibo[82];

int main() {
    init
    fibo[1] = 1;
    fibo[2] = 1;
    
    for(int i=3; i<=80; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cin >> n;
    if(n == 1) cout << 4;
    else cout << fibo[n] * 4 + fibo[n-1] * 2;
    
}

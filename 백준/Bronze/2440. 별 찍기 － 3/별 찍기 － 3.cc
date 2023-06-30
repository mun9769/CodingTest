

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

int main() {
    init
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=n-i; j>0; j--){
            cout << "*";
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define mod 1'000'000'009



ll pascal[33][33];
int r, c, w;
ll answer;

int main() {
    pascal[1][1] = 1;

    for(int i=2; i<33; i++) {
        for(int j=1; j<=i; j++) {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }
    cin >> r >> c >> w;
    for(int i=r; i<r+w; i++) {
        for(int j=c; j<= c + i-r; j++) {
            answer += pascal[i][j];
        }
    }

    cout << answer;

}

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 20'001



int main() {
    cin.tie(0) ->sync_with_stdio(0);
    vector<int> v;
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(a), v.push_back(b), v.push_back(c);
    sort(v.begin(), v.end());
    for(int x: v) cout << x << ' ';

}

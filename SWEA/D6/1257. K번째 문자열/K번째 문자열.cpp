#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 2e9
#define Mxn 1'001

int T;
ll n;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        int k;
        string str;
        cin >> k >> str;
        vector<string> v;

        for(int i=0; i<str.size(); i++) {
            for(int j=1; j<=str.size(); j++) {
                string sub_str = str.substr(i, j);
                v.push_back(sub_str);
            }
        }
        sort(v.begin(), v.end());

        v.erase(unique(v.begin(), v.end()), v.end());

        cout <<'#'<<tc<<' ';
        if(k > v.size())
            cout <<"none\n";
        else {
            cout << v[k-1] << '\n';
        }
    }
}
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
        vector<string> v;
        string str;
        int k;
        cin >> k;
        cin >> str;

        for(int i=str.size()-1; i>=0; i--) {
            int len = str.size() - i;
            string sub_str = str.substr(i, len);
            v.push_back(sub_str);
        }

        sort(v.begin(), v.end());

        cout <<'#'<<tc<<' ';
        
        if(k >= str.size()) cout << "none\n";
        else cout << v[k-1] << '\n';
    }
}
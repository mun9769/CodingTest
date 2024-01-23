#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using ll = long long;
using pll = pair<long long, long long>;
using plll = tuple<long long, long long, long long>;
#define inf 987654321
#define Mxn 1'001

int T;
int n, m;
string str;


int main(void) {
    cin.tie(0)->sync_with_stdio(0);
//    freopen("sample_input.txt", "r", stdin);


    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        vector<string> A;
        vector<string> B;
        int answer = 0;

        cin >> n >> m;
        for(int i=0; i<n; i++)
            cin >> str, A.push_back(str);
        for(int i=0; i<m; i++)
            cin >> str, B.push_back(str);

        sort(A.begin(), A.end());

        for(auto x: B) {
            auto lb = lower_bound(A.begin(), A.end(), x);
            if(*lb == x)
                answer++;
        }


        cout <<'#'<<tc<<' ';
        cout << answer << '\n';
    }



    return 0;
}
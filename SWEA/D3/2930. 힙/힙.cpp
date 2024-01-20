#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using dd = pair<double, double>;
using iii = tuple<int, int, int>;
using ll = long long;
using pll = pair<long long, long long>;
#define inf 987654321
#define Mxn 1'001

int T;
int n;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;

    for(int tc=1; tc<=T; tc++) {
        cout <<'#'<<tc<<' ';
        
        priority_queue<int> pq;
        cin >> n;
        for(int i=0; i<n; i++) {
            int command;
            cin >> command;
            if(command == 1) {
                int num; cin >> num;
                pq.push(num);
            }
            else if(command == 2) {
                if(pq.empty())
                    cout << -1 << ' ';
                else 
                    cout << pq.top() << ' ', pq.pop();
            }
        }
        cout << '\n';
    }
}
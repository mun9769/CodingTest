#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;


int n, m;
deque<int> dq;
vector<int> v;
int ans;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        dq.push_back(i);

    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i=0; i<m; i++) {
        int target = v[i];
        int idx = 0;
        for(idx=0; idx<dq.size(); idx++) {
            if(dq[idx] == target) break;
        }
        assert(idx < dq.size());

        int l = idx;
        int r = dq.size() - idx;

        if(l < r) {
            while(l-- > 0) {
                int num = dq.front();
                dq.push_back(num);
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        }
        else {
            while(r-- > 0) {
                int num = dq.back();
                dq.push_front(num);
                dq.pop_back();
                ans++;
            }
            dq.pop_front();
        }
    }
    cout << ans;


}

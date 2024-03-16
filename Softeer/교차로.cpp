#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
queue<int> road[4];
int n;
int ans[200'005];
vector<iii> ready;

int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(0);
    fill(ans, ans+200'005, -1);
    cin >> n;
    for(int i=0; i<n; i++){
        int t; char w;
        cin >> t >> w;
        ready.push_back({t, i, w-'A'}); 
    }
    sort(ready.begin(), ready.end());
    
    int cur = get<0>(ready[0]);
    int p = 0;
    int pass = 0;
    
    while(pass < n) {
        // 채우기
        assert(pass < 200'005);
        while(p < n) {
            auto [t, id, w] = ready[p];
            if(t <= cur) {
                road[w].push(id);
                p++;
            }
            else {
                break;
            }
        }

        int cnt = 0;
        vector<int> accepted;
        for(int w=0; w<4; w++) {
            if(road[w].size()) cnt++;
            if(road[w].size() and road[(w + 3) % 4].empty()) {
                accepted.push_back(w);
            }
        }
        for(auto w: accepted) {
            int id = road[w].front();
            ans[id] = cur;
            road[w].pop();
            pass++;
        }
        cur++;
        if(cnt == 4) {
            break; // 병목현상
        } else if(cnt == 0) {
            cur = get<0>(ready[p]);
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << '\n';
    }
   return 0;
}

#include<bits/stdc++.h>
using namespace std;

int h, k, r;
queue<int> q[2200];
int ans;
void exe(int id, int lv) {
    if(id >= pow(2, h+1)) 
        return;
    if(q[id].size()) {
        q[id/2].push(q[id].front());
        q[id].pop();
    } // id == 0 에 쌓임
    if(lv % 2 == 0) {
        exe(id*2, lv-1);
        exe(id*2+1, lv-1);
    }
    else {
        exe(id*2+1, lv-1);
        exe(id*2, lv-1);
    }
}


int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> k >> r;
    for(int i=pow(2, h); i<pow(2,h+1); i++) {
        for(int j=0; j<k; j++) {
            int num;
            cin >> num;
            q[i].push(num);
        }
    }
    for(int i=1; i<=r; i++){
        exe(1, h);
    }
    while(q[0].size()) {
        ans += q[0].front();
        q[0].pop();
    }
    cout << ans;

    
   return 0;
}

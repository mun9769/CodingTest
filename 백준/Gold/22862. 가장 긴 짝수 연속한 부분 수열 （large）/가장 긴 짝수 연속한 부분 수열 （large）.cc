#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1'000'004];

int node[1'000'005];
int edge[1'000'005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int p = 0;
    int i = 0;
    for(i=0; i<n; i++) {
        if(arr[i] % 2 == 0)
            break;
    }

    for(; i<n; ) {
        int cur = i;
        bool e = (arr[cur] % 2 == 0) ? true : false;
        if(e) {
            while(cur < n and arr[cur] % 2 == 0)
                cur++;
            node[p] = cur - i;
        }
        else {
            while(cur < n and arr[cur] % 2 == 1)
                cur++;
            edge[p++] = cur - i;
        }
        i = cur;
    }

    for(i=0; i<1'000'004 and node[i] != 0; i++){
    }
    int sz = i;
    int ans = node[0];
    int cnt = node[0];
    int cost = 0;

    int a = 0, b = 1;
    for(;b < sz;) {
        if(cost + edge[b-1] <= k) {
            cost += edge[b-1];
            cnt += node[b];
            b++;
        }
        else {
            if(a+1 == b) {
                a++; b++;
                cnt = node[a];
            }
            else {
                cnt -= node[a];
                cost -= edge[a];
                a++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;

}

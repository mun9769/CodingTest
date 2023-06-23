//
//  main.cpp
//  cpp
//
//  Created by moon on 2023/06/20.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <tuple>

#define init cin.tie(0)->ios_base::sync_with_stdio(0);
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define INF 1e9 + 3
using namespace std;


int n, m;
int arr[100'005];
int seg[250'005];

int getMn(int idx, int st, int en, int l, int r){
    
    if(l <= st and en <= r) return seg[idx];
    if(en < l || r < st) return INF;
    
    
    int mid = (st+en) / 2;
    
    int left = getMn(idx*2, st, mid, l, r);
    int right = getMn(idx*2+1, mid+1, en, l, r);
    
    return min(left, right);
}

int update(int idx, int st, int en, int i){
    if(st == en){
        return seg[idx] = arr[i];
    }
    int mid = (st+en) / 2;
    
    int val;
    
    if(i <= mid) val = update(idx*2, st, mid, i);
    else val = update(idx*2+1, mid+1, en, i);
    
    return seg[idx] = min(seg[idx], val);
    
}

int main() {
    init
    cin >> n >> m;
    for(int i=1; i<=n; i++){ cin >> arr[i]; }
    
    fill(seg, seg+250'000 , INF);
    
    for(int i=1; i<=n; i++){
        update(1, 1, n, i);
    }
    
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        cout << getMn(1, 1, n, a, b)<< '\n';
    }
    
    
    
    
}

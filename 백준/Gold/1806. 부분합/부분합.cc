#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;
 
typedef long long ll;
#define ii pair<int, int>
#define INF 987654321
 
int n, s;
vector<int> v;
 
int main()
{
    cin.tie(0)->ios_base::sync_with_stdio(0);

    cin >> n >> s;
    for(int i=0; i<n ;i++){
        int a; cin >> a;
        v.push_back(a);
    }

    int l = 0;
    int r = 0;

    int sum = v[0];
    int ans = INF;

    bool possible = true;

    while(possible){
        possible = false;

        while(sum < s){
            r++;
            if(r >= n) break;
            sum += v[r];
        }
        if(sum >= s) possible = true;

        while(sum >= s){
            ans = min(ans, r-l);
            sum -= v[l];
            l++;
        }
    }
    if(ans == INF) cout << 0;
    else cout << ans + 1;


}
 

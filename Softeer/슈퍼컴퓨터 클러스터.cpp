#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll n, b;
ll arr[100'005];
ll lf = INT32_MAX;
ll rh = INT32_MAX;
int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> b;
    for(int i=0; i<n; i++){
        cin >> arr[i];
         lf = min(lf, arr[i]);       
    }
    while(lf + 1 < rh) {
        ll mid = (lf+rh) / 2;
        ll total = 0;
        for(int i=0; i<n; i++) {
            if(mid <= arr[i]) continue;
            ll price = pow(mid-arr[i], 2); 
            total += price;

            if(total > b) 
                break;
        }

        if(total > b) {
            rh = mid;
        }
        else {
            lf = mid;
        }
    }
    cout << lf;

   return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n;
int arr[20'005];
ll answer;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }
    
    sort(arr, arr+n);
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            auto ub = upper_bound(arr+j+1, arr+n, -arr[i] - arr[j]);
            auto lb = lower_bound(arr+j+1, arr+n, -arr[i] - arr[j]);
            answer += ub - lb;
        }
    }
    cout << answer;

}
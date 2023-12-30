#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n;
int arr[100'005];
ll answer;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    int acc = accumulate(arr, arr+n, 0);

    for(int i=0; i<n; i++) {
        acc -= arr[i];
        answer += arr[i] * acc;
    }
    cout << answer;

}
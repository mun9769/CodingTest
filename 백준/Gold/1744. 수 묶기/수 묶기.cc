#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n;
int arr[20'005];
int answer;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int i = 0;

    while(i+1 < n and arr[i+1] <= 0) {
        int a = arr[i];
        int b = arr[i+1];

        answer += a * b;
        i += 2;
    }
    if(arr[i] < 0) answer += arr[i];

    i = n-1;
    while(i-1 >= 0 and arr[i-1] > 1) {
        int a = arr[i];
        int b = arr[i-1];

        answer += a * b;
        i -= 2;
    }
    if(arr[i] > 1) answer += arr[i];

    answer += count(arr, arr+n, 1);

    cout << answer;


}
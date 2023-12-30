#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n;
int arr[20'005];
ll answer;
int cnt[10'005];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr+n);

    for(int i=0; i<n-1; i++) {
        int l = i+1;
        int r = n-1;

        while(l < r) {
            int sum = arr[i] + arr[l] + arr[r];

            if(sum == 0) {
                if(arr[l] == arr[r]) {
                    answer += ((r - l + 1) * (r - l) / 2);
                    break;
                }

                else {
                    int tl = 1, tr = 1;
                    while(arr[l] == arr[l+1])
                        l++, tl++;
                    while(arr[r] == arr[r-1])
                        r--, tr++;
                    answer += tl * tr;
                    l++; r--;
                }
            }
            else if(sum > 0) {
                r--;
            }
            else if(sum < 0) {
                l++;
            }
        }
    }

    cout << answer;

}
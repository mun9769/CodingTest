#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


int n, k;
int arr[200'004];
ll answer;
map<int, ll> acc_count;


int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    int acc = 0;
    acc_count[0]++;

    for(int i=0; i<n; i++) {
        acc += arr[i];
        int desired = acc - k;

        answer += acc_count[desired];
        acc_count[acc]++;
    }

    cout << answer;
}

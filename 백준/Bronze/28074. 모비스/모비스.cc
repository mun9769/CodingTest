#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

string str;
int arr[26];


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    for(auto c: str) {
        arr[c - 'A']++;
    }
    string ans = "YES";
    for(auto c: {'M', 'O', 'B', 'I', 'S'}) {
        if(arr[c-'A'] == 0) {
            ans = "NO";
        }
    }
    cout << ans;

    return 0;
}

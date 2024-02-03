#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int n;

int counting[10005];
int num;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        counting[num]++;
    }
    for(int i=0; i<=10'000; i++) {
        for(int j=0; j<counting[i]; j++) {
            cout << i << '\n';
        }
    }

}

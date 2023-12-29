#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int n, k;
priority_queue<int> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        pq.push(num);

        while(pq.size() > k) { pq.pop(); }
    }
    cout << pq.top();

}

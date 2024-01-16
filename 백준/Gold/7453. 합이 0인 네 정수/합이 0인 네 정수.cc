#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 20'001


int n;
int A[4002];
int B[4002];
int C[4002];
int D[4002];

int AB[17'000'000];
int CD[17'000'000];
ll answer;

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            AB[n*i+j] = A[i] + B[j];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            CD[n*i+j] = C[i] + D[j];

    sort(AB, AB+ n*n);
    sort(CD, CD+ n*n);

    for(int i=0; i<n*n; i++) {
        int desired = -AB[i];

        auto lb = lower_bound(CD, CD+n*n, desired);
        auto ub = upper_bound(CD, CD+n*n, desired);

        answer += ub - lb;
    }

    cout << answer;


}

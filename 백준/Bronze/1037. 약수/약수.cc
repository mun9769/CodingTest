#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

vector<int> adj[500'005];
vector<int> ch[500'005];
int n;
ll tTurn;


vector<int> v;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    if (v.size() == 1) {
        cout << v[0] * v[0];
    }
    else {
        cout << *v.begin() * *v.rbegin();
    }

}

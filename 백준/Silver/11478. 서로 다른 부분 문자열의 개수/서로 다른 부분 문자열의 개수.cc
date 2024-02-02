#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    set<string> us;
    for (int i = 0; i < str.size(); i++) {

        for (int sz = 1; i + sz <= str.size(); sz++) {
            string sub = str.substr(i, sz);
            us.insert(sub);
        }
    }
    cout << us.size();

    return 0;
}

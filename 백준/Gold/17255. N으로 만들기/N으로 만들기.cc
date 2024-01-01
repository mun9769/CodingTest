#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define mod 1'000'000'009


string str;
int answer;
set<string> repo;

void dfs(int l, int r, string acc) {
    if(l == 0 and r == str.size()-1 and repo.find(acc) == repo.end()) {
        repo.insert(acc);
        answer++;
        return;
    }

    int len = r - l + 1;

    if(l > 0)            { dfs(l - 1, r, acc + str.substr(l-1, len+1)); }
    if(r < str.size()-1) { dfs(l, r + 1, acc + str.substr(l, len+1)); }
}

int main() {
    cin >> str;

    for(int i=0; i<str.size(); i++) {
        string ancestor = string(1, str[i]);
        dfs(i, i, ancestor);
    }

    cout << answer;

}

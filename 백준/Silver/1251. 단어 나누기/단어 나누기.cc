#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;



string str;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> str;
    set<string> repo;

    for (int i = 1; i < str.size()-2; i++) {
        string a = str.substr(0, i);
        reverse(a.begin(), a.end());
        for (int j = 1; i + j < str.size(); j++) {
            string b = str.substr(i, j);
            string c = str.substr(i+j, str.size() -i-j);
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            string tot = a + b + c;
            repo.insert(tot);
        }
    }

    cout << *repo.begin();

}

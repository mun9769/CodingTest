#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


int n;
string s;



int main() {
    while(cin >> n) {
        if(n == 0) break;

        vector<string> v;
        map<string, string> table;

        for(int i=0; i<n; i++){
            cin >> s;
            string converted;
            for(auto c: s) {
                converted.push_back(tolower(c));
            }

            table[converted] = s;

            v.push_back(converted);
        }
        sort(v.begin(), v.end());

        cout << table[v[0]] << '\n';

    }
}

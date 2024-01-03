#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321




int main() {
    string str;
    while(true) {
        getline(cin, str);
        if(str == "END") break;

        reverse(str.begin(), str.end());
        cout << str << '\n';
    }

}

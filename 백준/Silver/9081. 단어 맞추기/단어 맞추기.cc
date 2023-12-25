#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
#define sz 22

int n;
int m;



int answer = 0;

int main() {
    cin >> n;
    while(n-- > 0) {
        string str;
        cin >> str;
        string _str = str;
        bool ready = false;
        bool show = false;
        do {
            if(ready) { cout << str << '\n'; show = true; break; }
            ready = true;
        } while(next_permutation(str.begin(), str.end()));
        if(show == false) { cout << _str << '\n'; }
    }

}

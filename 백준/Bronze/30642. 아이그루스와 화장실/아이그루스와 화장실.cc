#include <bits/stdc++.h>
using namespace std;

const int inf = 987654321;

int n;
int k;
string str;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> str;
    cin >> k;
    if(str == "annyong") {
        if(k % 2 == 1) {
            cout << k;
        }
        else {
            cout << k-1;
        }
    }
    else {
        if(k % 2 == 1) {
            if(k != 1)
                cout << k-1;
            else
                cout << k+1;
        }
        else {
            cout << k;
        }
    }

    return 0;
}

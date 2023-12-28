#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


string str;

set<string> croatia = {
        "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};
int answer;

int main() {
    cin >> str;
    int i = 0;
    while(i < str.size()) {

        string target;
        target += str[i];
        for(int j=i+1; j<=i+2; j++) {
            if(j >=str.size()) break;
            target.push_back(str[j]);

            if(croatia.find(target) != croatia.end()) {
                i = j;
                break;
            }
        }

        answer++;
        i++;
    }
    cout << answer;
}

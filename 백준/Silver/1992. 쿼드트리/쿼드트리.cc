#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;

int n;
string str;

vector<string> img;

vector<string> to_sub(vector<string>& src, int dir) {
    vector<string> result;
    int sz = src.size()/2;
    if(dir == 1) {
        for(int i=0; i<sz; i++) {
            result.push_back(src[i].substr(0, sz));
        }
    }
    else if(dir == 2) {
        for(int i=0; i<sz; i++) {
            result.push_back(src[i].substr(sz, sz));
        }
    }
    else if(dir == 3) {
        for(int i=sz; i<2*sz; i++) {
            result.push_back(src[i].substr(0, sz));
        }
    }
    else if(dir == 4) {
        for(int i=sz; i<2*sz; i++) {
            result.push_back(src[i].substr(sz, 2*sz));
        }
    }
    return result;
}

string dfs(vector<string> src) {
    string result;
    bool all_zero = true;
    bool all_bit = true;
    for(int i=0; i<src.size(); i++) for(int j=0; j<src.size(); j++) {
        if(src[i][j] == '0') all_bit = false;
        else all_zero = false;
    }

    if(all_zero) { return "0"; }
    if(all_bit) { return "1"; }

    vector<string> sub_str;

    sub_str = to_sub(src, 1);
    result += dfs(sub_str);
    sub_str = to_sub(src, 2);
    result += dfs(sub_str);
    sub_str = to_sub(src, 3);
    result += dfs(sub_str);
    sub_str = to_sub(src, 4);
    result += dfs(sub_str);

    return "(" + result + ")";

}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        img.push_back(str);
    }
    cout << dfs(img);
}

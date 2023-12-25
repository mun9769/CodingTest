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
        stack<char> s;

        for(char x: str)  {
            if(s.size() and s.top() == x) { s.pop(); }
            else { s.push(x); }
        }
        if(s.empty()) answer++;
    }
    cout << answer;

}

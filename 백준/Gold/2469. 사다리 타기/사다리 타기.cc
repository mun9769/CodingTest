#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
#define sz 22

int k, n;
string str;
vector<string> top, btm;
string input, output;

void setup() {
    cin >> k >> n;
    cin >> output;

    while(cin >> str) {
        n--;
        if(str[0] == '?') break;
        top.push_back(str);
    }
    while(n-- > 0 and cin >> str) {
        btm.push_back(str);
    }
    reverse(btm.begin(), btm.end());

    for(int i=0; i<output.size(); i++)
        input.push_back('A' + i);
}

int main() {
    setup();

    for(string str: top) {
        for(int i=0; i<str.size(); i++) {
            bool changer = str[i] == '-' ? true : false;

            if(changer)
                swap(input[i], input[i+1]);
        }
    }

    for(string str: btm) {
        for(int i=0; i<str.size(); i++) {
            bool changer = str[i] == '-' ? true : false;

            if(changer)
                swap(output[i], output[i+1]);
        }
    }

    string answer;
    for(int i=0; i<input.size()-1; i++) {
        if(input[i] == output[i]) {
            answer.push_back('*');
        }
        else if(input[i] == output[i+1] and input[i+1] == output[i]) {
            swap(input[i], input[i+1]);
            answer.push_back('-');
        }
    }

    if(answer.size() == k-1) cout << answer;
    else for(int i=0; i<k-1; i++) cout << 'x';
}

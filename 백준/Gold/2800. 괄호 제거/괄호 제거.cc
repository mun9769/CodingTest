#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

string input;

vector<ii> brace;
stack<int> s;

int main() {
    cin >> input;

    for(int i=0; i<input.size(); i++) {
        if(input[i] == '(') s.push(i);
        else if(input[i] == ')') {
            if(s.empty()) throw std::logic_error("");
            int k = s.top();
            s.pop();
            brace.push_back({k, i});
        }
    }

    int n = brace.size();
    vector<string> answer;
    for(int i=1; i< (1<<n); i++) {
        // i의 n번째가 0이면 ㄱㅊ
        // i의 n번째가 1이면 안나옴.
        set<int> exclude_brace_index;
        for(int j=0; j<n; j++) {
            if(i & (1 << j)) {
                auto [st, en] = brace[j];
                exclude_brace_index.insert(st);
                exclude_brace_index.insert(en);
            }
        }
        string brace_removed_string;
        for(int x=0; x<input.size(); x++) {
            if(exclude_brace_index.find(x) != exclude_brace_index.end()) continue;
            brace_removed_string.push_back(input[x]);
        }
        answer.push_back(brace_removed_string);
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for(string x: answer) {
        cout << x << endl;
    }

}

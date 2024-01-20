#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 20'001

int n;
int T = 10;
int _left[200];
int _right[200];
char word[200];

vector<string> _split(string input) {
    vector<string> result;
    int pos = 0;
    while((pos = input.find(' ')) != string::npos) {
        string word = input.substr(0, pos);
        input.erase(0, pos+1);
        result.push_back(word);
    }
    result.push_back(input);
    return result;
}

void dfs(int cur) {

    if(_left[cur] != -1) dfs(_left[cur]);
    cout << word[cur];
    if(_right[cur] != -1) dfs(_right[cur]);

}

int main() {
    cin.tie(0) ->sync_with_stdio(0);

    for(int test_case = 1; test_case <= T; test_case++) {
        for(int i=0; i<200; i++) _left[i] = -1, _right[i] = -1;
        cin >> n;
        cin.ignore();

        for(int i=0; i<n; i++) {
            string s;
            getline(cin, s);
            auto words = _split(s);

            int id, lft = -1, rht = -1;
            char c;
            id = stoi(words[0]);
            c = words[1][0];
            if(words.size() >= 3) lft = stoi(words[2]);
            if(words.size() == 4) rht = stoi(words[3]);

            if(lft != -1) _left[id] = lft;
            if(rht != -1) _right[id] = rht;
            word[id] = c;

        }

        cout << '#'<<test_case<<' ';
        dfs(1);
        cout << '\n';

    }

    return 0;

}

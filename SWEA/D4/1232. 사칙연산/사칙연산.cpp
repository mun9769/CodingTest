#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 1'001

int n;
int T = 10;
int _left[Mxn];
int _right[Mxn];
int number[Mxn];
char word[Mxn];
int answer;

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

double dfs(int cur) {

    if(_left[cur] == -1)
        return number[cur];

    char oper = word[cur];
    auto lft = dfs(_left[cur]);
    auto rht = dfs(_right[cur]);

    if(oper == '*') return lft * rht;
    else if(oper == '+') return lft + rht;
    else if(oper == '-') return lft - rht;
    else if(oper == '/') return lft / rht;

    throw logic_error("잘못된 연산입니다");
}

int main() {
    cin.tie(0) ->sync_with_stdio(0);

    for(int test_case = 1; test_case <= T; test_case++) {
        for(int i=0; i<Mxn; i++) _left[i] = -1, _right[i] = -1;
        cin >> n;
        cin.ignore();

        for(int i=0; i<n; i++) {
            string s;
            getline(cin, s);
            auto words = _split(s);

            if(words.size() == 4) {
                int id, lft = -1, rht = -1;
                char c;
                id = stoi(words[0]); c = words[1][0];
                lft = stoi(words[2]); rht = stoi(words[3]);

                word[id] = c;
                _left[id] = lft;
                _right[id] = rht;
            }
            else if(words.size() == 2) {
                int id, num;
                id = stoi(words[0]);
                num = stoi(words[1]);
                number[id] = num;
            }
            else
                throw std::logic_error("잘못된 입력입니다.");

        }

        cout << '#'<<test_case<<' ';
        answer = dfs(1);
        cout << (int)answer << '\n';

    }

    return 0;

}

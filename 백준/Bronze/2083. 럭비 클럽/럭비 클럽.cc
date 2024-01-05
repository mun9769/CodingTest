#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 20'001

string str;

vector<string> _split(string input) {
    vector<string> result;
    string word;
    for(int i=0; i<input.size(); i++) {
        if(input[i] != ' ')
            word.push_back(input[i]);
        else
            result.push_back(word), word = "";
    }
    result.push_back(word);
    return result;
}

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    while(true) {
        getline(cin, str);
        if(str[0] == '#')
            break;

        vector<string> person  = _split(str);
        int age = stoi(person[1]);
        int weight = stoi(person[2]);

        if(age > 17 or weight >= 80)
            cout << person[0] << " Senior" << '\n';
        else
            cout << person[0] << " Junior" << '\n';
    }
}

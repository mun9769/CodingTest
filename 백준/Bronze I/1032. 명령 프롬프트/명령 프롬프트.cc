#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define off 50


int n;
string str;
string answer;

int main()
{
    cin >> n;
    cin >> answer;
    for(int i=0; i<n-1; i++) {
        cin >> str;
        for(int x=0; x<answer.size(); x++) {
            if(answer[x] != str[x]) answer[x] = '?';
        }
    }
    cout << answer;

}
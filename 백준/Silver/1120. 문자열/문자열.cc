#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321


string a, b;

int main()
{
    cin >> a >> b;
    int mx = -1;
    for(int i=0; i<=b.size() - a.size(); i++) {
        int match = 0;
        for(int j=0; j<a.size(); j++) {
            if(b[i+j] == a[j])
                match++;
        }
        if(mx < match) {
            mx = match;
        }
    }
    int answer = a.size() - mx;

    cout << answer;

}
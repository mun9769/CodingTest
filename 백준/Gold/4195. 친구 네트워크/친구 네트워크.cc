#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int t;
int p[200'003];
int sz[200'003];

int Find(int x) {
    if(x == p[x]) return x;

    return p[x] = Find(p[x]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t-- > 0) {

        for(int i=0; i<200'003; i++) { p[i] = i; sz[i] = 1; }
        unordered_map<string, int> lst;
        int member = 0;
        int f;
        string a, b;
        int idA, idB;
        cin >> f;

        for(int i=0; i<f; i++) {
            cin >> a >> b;
            if (lst.find(a) == lst.end()) { lst[a] = member++; } // 회원 등록
            if (lst.find(b) == lst.end()) { lst[b] = member++; }

            idA = lst[a];
            idA = Find(idA);
            idB = lst[b];
            idB = Find(idB);
            if(idA == idB) {
                cout << sz[idA] << '\n';
            }
            else {
                p[idA] = idB; // Union
                sz[idB] = sz[idB] + sz[idA];
                sz[idA] = sz[idB] + sz[idA];
                cout << sz[idB] << '\n';
            }
        }
    }

}

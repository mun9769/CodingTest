#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define Mxn 20'001

int n, m;
int T = 10;
char command;
int num;

int main() {
    cin.tie(0) ->sync_with_stdio(0);

    for(int test_case = 1; test_case <= T; test_case++) {
        list<int> li;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> num;
            li.push_back(num);
        }

        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> command;
            int x, y;
            auto iter = li.begin();

            if (command == 'I') {
                cin >> x >> y;
                advance(iter, x);
                for (int j = 0; j < y; j++)
                    cin >> num, li.insert(iter, num);
            }
            else if (command == 'A') {
                cin >> y;
                for (int j = 0; j < y; j++)
                    cin >> num, li.push_back(num);
            }
            else if (command == 'D') {
                cin >> x >> y;
                advance(iter, x);

                for (int j = 0; j < y; j++)
                    iter = li.erase(iter);
            }
        }

        cout << "#"<<test_case << ' ';
        auto iter = li.begin();
        for(int i=0; i<10; i++) {
            cout << *iter << ' ';
            iter++;
        }
        cout << '\n';
    }

	return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int test_case;
    cin >> test_case;
    while(test_case-- > 0) {

        multiset<int> dpq;
        int query;
        cin >> query;
        for(int q = 0; q<query; q++) {
            char c;
            int num;
            cin >> c >> num;
            if(c == 'I') {
                dpq.insert(num);
                continue;
            }

            if(num == 1 and dpq.size()) {
                auto iter = --dpq.end();
                dpq.erase(iter);
            }
            else if(num == -1 and dpq.size()) {
                dpq.erase(dpq.begin());
            }
        }

        if(dpq.empty())
            cout << "EMPTY" << '\n';
        else {
            cout << *dpq.rbegin() << ' ' << *dpq.begin() << '\n';
        }
    }
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


int main() {
    int test_case;
//    multiset<int> ts;
//    ts.insert(2);
//    ts.insert(2);
//    ts.insert(2);
//
//    ts.erase(ts.begin());
//
//    cout << ts.size();
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
            cout << "EMPTY" << endl;
        else {
            cout << *dpq.rbegin() << ' ' << *dpq.begin() << endl;
        }
    }
}

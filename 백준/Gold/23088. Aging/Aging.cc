#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int n;

vector<iii> process;
int a, b, c;
int endpoint;

struct cmp {
    bool operator()(const iii& a, const iii& b) {
        auto& [x, y, z] = a;
        auto& [p, q, w] = b;

        if(get<0>(a) == get<0>(b)) {

            if(get<1>(a) == get<1>(b)) {
                // return z < w;
                return get<2>(a) > get<2>(b);
            }
            // return y > q;
            return get<1>(a) > get<1>(b);
        }
        // return a < b;
        return get<0>(a) < get<0>(b);

    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;
        process.push_back({a, b, c});
    }

    auto p = process.begin();
    endpoint = get<0>(*p);
    priority_queue<iii,vector<iii>, cmp> pq; 



    while(p != process.end()) {

        while(p != process.end() and get<0>(*p) <= endpoint) {
            auto [st, priority, len] = *p;
            priority -= st;
            int id = p - process.begin();

            pq.push({priority, len, id});
            p++;
        }

        auto [_, __, id] = pq.top();
        pq.pop();

        endpoint += get<2>(process[id]);
        cout << id + 1 << ' ';

    }
    while(pq.size()) {
        cout << get<2>(pq.top()) + 1 << ' ';
        pq.pop();
    }

}

#include <bits/stdc++.h>
using namespace std;

map<int, int> item;
priority_queue<int> pq;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(auto sz: tangerine) {
        item[sz]++;
    }
    
    for(auto [sz, amount]: item) {
        pq.push(amount);
    }
    
    int total = 0;
    while(pq.size() and total < k) {
        int amount = pq.top();
        pq.pop();
        total += amount;
        answer++;
    }
    
    return answer;
}
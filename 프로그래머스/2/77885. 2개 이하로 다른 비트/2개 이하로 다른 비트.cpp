#include <bits/stdc++.h>
using namespace std;

long long diff(long long x) {
    vector<int> v;
    
    while(x > 0) {
        int remainder = x % 2;
        x = x / 2;
        v.push_back(remainder);
    }
    v.push_back(0);
    
    int one_amount = 0;
    for(auto bit: v) {
        if(bit == 0) break;
        else one_amount++;
    }
    
    if(one_amount == 0)
        return 1;
    else 
        return (long long)pow(2, one_amount-1);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto x: numbers) {
        auto f_x = x + diff(x);
        answer.push_back(f_x);
    }
    return answer;
}
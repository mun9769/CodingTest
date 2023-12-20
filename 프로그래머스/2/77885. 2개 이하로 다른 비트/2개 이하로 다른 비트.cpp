#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto x: numbers) {
        long long bit = 1;
        while( (x & bit) == bit) bit <<= 1;
        
        long long diff = bit >> 1;
        if(bit == 1) diff = 1;
        long long fx = x + diff;
        
        answer.push_back(fx);
    }
    return answer;
}
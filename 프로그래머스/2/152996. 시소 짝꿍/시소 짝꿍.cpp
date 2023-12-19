#include <bits/stdc++.h>
using namespace std;

map<double, long long> nums;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for(auto x: weights) { nums[(double)x]++; }
    
    for(auto [key, value]: nums) {
       if(value >= 2)
            answer += value * (value - 1) / 2;
        
        double partner;
        
        partner = key * 2;
        if(nums.count(partner)) {
            answer += value * nums[partner];
        }
        
        partner = key * 3 / 2;
        if(nums.count(partner)) {
            answer += value * nums[partner];
        }
        
        partner = key * 4 / 3;
        if(nums.count(partner)) {
            answer += value * nums[partner];
        }
    }
    
    return answer;
}
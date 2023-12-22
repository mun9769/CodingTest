#include <bits/stdc++.h>
using namespace std;

vector<int> to_stone_vector(int k) {
    vector<int> result;
    result.push_back(k);
    
    while(k > 1) {
        int remainder;
        if(k % 2 == 0) {
            k = k / 2;
            result.push_back(k);
        }
        else {
            k = 3 * k + 1;
            result.push_back(k);
        }
    }
    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    auto stone_vector = to_stone_vector(k);
    
    vector<double> area;
    
    for(int i=0; i<stone_vector.size() - 1; i++) {
        double a = stone_vector[i];
        double b = stone_vector[i+1];
        
        double sum = 0;
        double mn = min(a, b);
        double mx = max(a, b);
        
        sum += mn;
        sum += (mx - mn) / 2.0;
        
        area.push_back(sum);
    }
    
    for(auto range: ranges) {
        int a = range[0];
        int b = stone_vector.size() - 1 + range[1];
        if(a > b) {
            answer.push_back(-1);
            continue;
        }
        double sum = 0;
        for(int i=a; i<=b-1; i++) {
            sum += area[i];
        }
        answer.push_back(sum);
    }
    
    return answer;
}
#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    if(y == 0){ return x; }
    return gcd(y, x%y);
}

vector<int> to_divide(int x) {
    vector<int> result;
    
    for(int i=x; i>0; i--){
        if(x % i == 0) 
            result.push_back(i);
    }
    return result;
}

vector<int> find_answer(vector<int>& array, vector<int>& child_vector) {
    
    vector<int> result;
    
    for(auto div: child_vector) {
        bool possible = true;
        for(auto x: array) {
            if(x % div == 0) {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            result.push_back(div);
            break;
        }
    }
    
    return result;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int div_a = arrayA[0];
    int div_b = arrayB[0];
    for(auto x: arrayA) { div_a = gcd(div_a, x);  }
    for(auto x: arrayB) { div_b = gcd(div_b, x);  }
    
    
    auto child_div_a = to_divide(div_a);
    auto child_div_b = to_divide(div_b);
    
    auto candidate_a = find_answer(arrayA, child_div_b);
    auto candidate_b = find_answer(arrayB, child_div_a);
    
    for(int x: candidate_a) {
        auto iter = find(candidate_b.begin(), candidate_b.end(), x);
        if(iter == candidate_b.end()) {
            answer = x;
            break;
        }
    }
    
    for(int x: candidate_b) {
        auto iter = find(candidate_a.begin(), candidate_a.end(), x);
        if(iter == candidate_a.end()) {
            answer = max(answer, x);
            break;
        }
    }
    
    
    
    return answer;
}
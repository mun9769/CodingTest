#include <bits/stdc++.h>
using namespace std;

vector<int> split_digit(int num) {
    vector<int> result;
    while(num > 0) {
        int unit = num % 10;
        num = num / 10;
        result.push_back(unit);
    }
    result.push_back(0);
    return result;
}
vector<int> storey;

void add_one(int& j) {
    while(j < storey.size()) {
        int& target = storey[j];
        target++;
        if(target == 10) {
            target = 0;
            j++;
        }
        else break;
    }
}

int solution(int _storey) {
    int answer = 0;
    storey = split_digit(_storey);
    for(int i=0; i<storey.size(); i++) {
        int x = storey[i];
        
        if(x == 5) {
            int j = i + 1;
            
            if(storey[j] >= 5) {
                add_one(j);
            }
            answer += 5;
        }
        else if(x < 5) answer += x;
        else {
            answer += 10 - x;
            
            int j = i+1;
            add_one(j);
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    for(int i=0; i<s; i++) {
        answer.push_back(my_string[i]);
    }
    
    for(auto x: overwrite_string) {
        answer.push_back(x);
    }
    
    for(int i=s+overwrite_string.size(); i<my_string.size(); i++) {
        answer.push_back(my_string[i]);
    }
    return answer;
}
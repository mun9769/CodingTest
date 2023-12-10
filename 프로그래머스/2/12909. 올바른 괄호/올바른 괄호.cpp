#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<int> v;

    for(auto x: s) {
        if(x == '(') v.push_back(0);
        
        else {
            if(v.empty()) answer = false;
            
            else v.pop_back();
        }
    }
    if(v.size()) answer = false;

    return answer;
}
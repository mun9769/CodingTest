#include <bits/stdc++.h>
using namespace std;


unordered_map<string, int> score;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0; i<yearning.size(); i++) {
        string n = name[i];
        score[n] = yearning[i];
    }
    for(vector<string> people: photo) {
        int sum = 0;
        
        for(auto x: people) {
            sum += score[x];
        }
        
        answer.push_back(sum);
        
    }
    return answer;
}
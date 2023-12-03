#include <bits/stdc++.h>
using namespace std;
#define task tuple<int, int, string>

stack<task> ready;
vector<string> answer;

int minutate(string start) {
    string hour = start.substr(0, 2);
    string min = start.substr(3, 5);
    // cout << hour << ' ' << min << endl;
    return stoi(hour) * 60 + stoi(min);
}



void execute(int& time) {
    auto [start, playtime, name] = ready.top();
    ready.pop();

    if(playtime <= time) {
        time = time - playtime;
        answer.push_back(name);
    }
    else {
        playtime = playtime - time;
        time = 0;
        ready.push({start, playtime, name});
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<task> parse_plans;
    vector<int> interval;
    for(vector<string>& plan: plans) {
        int start = minutate(plan[1]);
        int playtime = stoi(plan[2]);
        string name = plan[0];
        parse_plans.push_back({start, playtime, name});
    }
    sort(parse_plans.begin(), parse_plans.end());
    
    for(int i=0; i<parse_plans.size()-1; i++){
        interval.push_back(get<0>(parse_plans[i+1]) - get<0>(parse_plans[i]));
    }
    interval.push_back(get<1>(*parse_plans.rbegin()));
    
    
    for(int i=0; i<interval.size(); i++) {
        auto [start, playtime, name] = parse_plans[i];
        int time = interval[i];
        
        if(playtime <= time) {
            time = time - playtime;
            answer.push_back(name);
            
            while(ready.size() and time > 0) {
                execute(time);
            }
        }
        else {
            playtime = playtime - time;
            time = 0;
            ready.push({start, playtime, name});
        }
        
    }
    
    while(ready.size()) {
        auto [start, playtime, name] = ready.top();
        ready.pop();
        answer.push_back(name);
    }
    
    
    
    return answer;
}
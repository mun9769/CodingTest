#include <bits/stdc++.h>
using namespace std;



enum event {
    release, enter, 
};
using task = pair<int, event>;

struct CompareTask {
    bool operator()(task& lhs, task& rhs) {
        if(lhs.first == rhs.first) {
            return lhs.second > rhs.second;
        }
        
        return lhs.first > rhs.first;
    }
};



priority_queue<task, vector<task>, CompareTask> schedule;

int to_minute(string s) {
    string hour = s.substr(0, 2);
    string minute = s.substr(3, 2);
    
    int hour_int = stoi(hour);
    int minute_int = stoi(minute);
    
    return hour_int * 60 + minute_int;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(auto book: book_time) {
        int enter_time = to_minute(book[0]);
        int release_time = to_minute(book[1]);
        
        schedule.push({enter_time, event::enter});
        schedule.push({release_time + 10, event::release});
    }
    
    int using_room = 0;
    
    while(schedule.size()) {
        auto [time, type] = schedule.top();
        schedule.pop();
        
        switch(type) {
            case event::enter:
                using_room++;
                answer = max(answer, using_room);
                break;
            case event::release:
                using_room--;
                break;
        }
    }
    return answer;
}
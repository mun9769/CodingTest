#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int cur = section[0];
    auto iter = section.begin();
    
    while(iter != section.end()) {
        answer++;
        iter = lower_bound(section.begin(), section.end(), *iter + m);
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    std::sort(citations.begin(), citations.end());
    int n = citations.size();
    
    for(int i=0; i<=10'000; i++){
        int h = i;
        auto iter = lower_bound(citations.begin(), citations.end(), h);
        int index = iter - citations.begin();
        int cnt = n - index;
        if(cnt >= h) answer = h;
    }
    return answer;
}

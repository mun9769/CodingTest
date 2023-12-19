#include <string>
#include <vector>
#include <stack>
#define ii pair<int, int>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<ii> s;
    
    for(int i=0; i<numbers.size(); i++){
        while(s.size() and s.top().first < numbers[i]) {
            auto [x, index] = s.top();
            s.pop();
            answer[index] = numbers[i];
        }
        s.push({numbers[i], i});
    }
    return answer;
}
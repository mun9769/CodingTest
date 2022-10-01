#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(auto num : numbers){
        answer += (double)num;
    }
    answer /= (double)numbers.size();
    return answer;
}
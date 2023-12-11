#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int _x, int n) {
    vector<long long> answer;
    long long x = _x;
    for(int i=1; i<=n; i++){
        answer.push_back(x * i);
    }
    return answer;
}
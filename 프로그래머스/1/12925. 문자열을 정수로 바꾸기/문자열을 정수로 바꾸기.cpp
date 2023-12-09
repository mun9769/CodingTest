#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool sign = true;
    if(s[0] == '-') {
        sign = false;
        s = s.substr(1);
    }
    else if(s[0] == '+') {
        s = s.substr(1);
    }
    answer = std::stoi(s);
    if(sign == false) {
        answer = -answer;
    }
    return answer;
}
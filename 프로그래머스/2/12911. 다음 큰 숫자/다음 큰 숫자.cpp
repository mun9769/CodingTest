#include <string>
#include <vector>

using namespace std;

int count_bit(int n) {
    int ret = 0;
    while(n > 0) {
        if(n % 2 == 1) ret++;
        n = n / 2;
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    int desired = count_bit(n);
    
    for(int i=n+1; i < 3'000'000; i++) {
        int cmp = count_bit(i);
        if(cmp == desired) {
            answer = i;
            break;
        }
    }
    return answer;
}
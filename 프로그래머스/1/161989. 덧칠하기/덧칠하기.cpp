#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int done = section[0] + m;
    
	for(int i=0; i<section.size(); i++){
        if(section[i] < done) continue;
        
        done = section[i] + m;
        answer++;
    }
    
    
    return answer;
}
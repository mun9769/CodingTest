#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int x = 0;
    int other = 0;
    char stdChar = 'A';
    for(char c: s){
        if(stdChar == 'A'){
            stdChar = c;
            x = 1;
            continue;
        }
        else if(stdChar == c){
            x++;
        }
        else{
            other++;
        }
        if(x == other){
            x = 0;
            other = 0;
            stdChar= 'A';
            answer++;
        }
        
        
    }
    if(x > 0)
        answer++;
    return answer;
}
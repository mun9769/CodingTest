#include <string>
#include <vector>

using namespace std;

int arr[26];
int c2i(char c) {return c - 'a';}

vector<int> solution(string s) {
    fill(arr, arr+ 26, -1);
    vector<int> answer;
    for(int i=0; i<s.size(); i++){
        int num = c2i(s[i]);
        if(arr[num] == -1)
            answer.push_back(-1);
        else
            answer.push_back(i - arr[num]);
        arr[num] = i;
    }
    return answer;
}
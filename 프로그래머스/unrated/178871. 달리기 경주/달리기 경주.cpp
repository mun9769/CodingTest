#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> n2s;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    for(int i=0; i<players.size(); i++){
        n2s[players[i]] = i;
    }
    
    for(auto name: callings) {
        int right = n2s[name];
        int left = right - 1;
        string left_name = players[left];
        n2s[left_name]++;
        n2s[name]--;
        
        swap(players[right], players[right - 1]);
    }
    answer = players;
    return answer;
}
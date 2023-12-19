#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
using namespace std;
using ii = pair<int, int>;
#define inf 987654321

int n;

bool valid_string(string& s) {
    if(s.find("__") != s.npos) return false;
    if(s[0] == '_') return false;
    if(*s.rbegin() == '_') return false;
    
    if(isupper(s[0])) return false;
    
    bool has_upper = false;
    bool has_snake = false;
    
    for(auto x: s) if(isupper(x)) { has_upper = true; }
    if(s.find("_") != s.npos) has_snake = true;
    
    if(has_upper and has_snake) return false;
    
    return true;
}

int main() {
    string s;
    string answer;
    
    cin >> s;
    
    if(valid_string(s) == false) {
        cout << "Error!" << endl;
        return 0;
    }
    
    if(s.find("_") == s.npos) { // _가 없다면
        for(auto x: s) {
            if(std::isupper(x)) {
                answer.push_back('_');
                answer.push_back(tolower(x));
            }
            else {
                answer.push_back(x);
            }
        }
    }
    else {
        bool chk = false;
        for(int i=0; i<s.size(); i++) {
            if(chk) { 
                answer.push_back(toupper(s[i]));
                chk = false;
            }
            else if(s[i] == '_') {
                chk = true;
            }
            else {
                answer.push_back(s[i]);
            }
        }
    }
    cout << answer;
}

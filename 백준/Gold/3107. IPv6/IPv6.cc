#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool flag = false;

vector<string> split(string str, string delimiter) {
    vector<string> result;
    size_t prev = 0, cur = str.find(delimiter);

    while(cur != string::npos) // find는 원하는 문자열을 찾지 못하면 npos를 반환한다.
    {
    	string sub_str = str.substr(prev, cur - prev); // 문자열 split
        result.push_back(sub_str);
        prev = cur + 1;
        cur = str.find(delimiter, prev);
    }
    result.push_back(str.substr(prev, cur - prev)); // 마지막 split

    if(str.find("::") != string::npos) flag = true;

    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str, ans;
    cin >> str;

    vector<string> result = split(str, ":");
    vector<string> answer, tmp;

    if(result.size() != 8) {
        for(int i = 0 ; i < result.size() ; i++) {
            if(result[i].length() == 0 && flag) {
                for(int j = 0 ; j < 9 - result.size() ; j++) tmp.push_back("0000");
                flag = false;
            }
            else tmp.push_back(result[i]);
        }

        result = tmp;
    }
 
    for(int i = 0 ; i < 8 ; i++) {
        if(result[i].length() < 4) {
            string tmp;

            for(int j = 0 ; j < 4 - result[i].length() ; j++) tmp += '0';
            tmp += result[i];

            answer.push_back(tmp);
        }
        else answer.push_back(result[i]);
    }
    
    for(int i = 0 ; i < 8 ; i++) ans += i == 7 ? answer[i] : answer[i] + ":";
    cout << ans;

    return 0;
}
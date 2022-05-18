#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token="";
    while((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> v;

    unordered_map<string, string> m;

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> ret = split(record[i], " ");
        v.emplace_back(ret);

        if(ret[0] == "Enter")
			m[ret[1]] = ret[2];
        else if(ret[0] == "Change")
			m[ret[1]] = ret[2];
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] == "Enter")
        {
            string s = m[v[i][1]] + "님이 들어왔습니다.";
            answer.emplace_back(s);

        }
        else if (v[i][0] == "Leave")
        {
            string s = m[v[i][1]] + "님이 나갔습니다.";
            answer.emplace_back(s);
        }
    }
    return answer;
}

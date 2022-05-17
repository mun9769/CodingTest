#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> success;
    unordered_map<string, int> m;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < id_list.size(); i++)
    {
        success.insert({ id_list[i], 0 });
    }

    for (int i = 0; i < report.size(); i++)
    {
        vector<string> ret;
        ret = split(report[i], " ");

		if (m.find(ret[1]) == m.end())
			m.insert({ ret[1], 1 });
		else
			m[ret[1]]++;
    }

    for (int i = 0; i < report.size(); i++)
    {
        vector<string> ret = split(report[i], " ");
        if (m[ret[1]] >= k)
            success[ret[0]]++;
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        answer.push_back(success[id_list[i]]);
    }
    return answer;
}



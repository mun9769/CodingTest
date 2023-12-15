#include <bits/stdc++.h>
using namespace std;

map<string, int> dict = {
    {"code",    0},
    {"date",    1},
    {"maximum", 2},
    {"remain",  3}
};

int ext_category;
int sort_category;

bool cmp(vector<int>& a, vector<int>& b) {
	return a[sort_category] < b[sort_category];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    ext_category = dict[ext];
    sort_category = dict[sort_by];
    
    for(auto x: data) {
        if(x[ext_category] < val_ext) 
            answer.push_back(x);
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    
    return answer;
}
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

stack<int> s;

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int j;
    for(int i=0;i<prices.size()-1;i++)
    {
        for(j=i+1;j<prices.size()-1;j++)
            if(prices[j]<prices[i])
                break;

        answer.push_back(j-i);
    }
    answer.push_back(0);

    return answer;
}

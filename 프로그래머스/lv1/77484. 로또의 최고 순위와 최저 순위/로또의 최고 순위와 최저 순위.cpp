#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int correct = 0;
    int zeroCnt = 0;
    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)
            zeroCnt++;
        for (int j = 0; j < 6; j++)
        {
            if (lottos[i] == win_nums[j]) {
                correct++;
                break;
            }
        }
    }
    int max = 7 - zeroCnt - correct < 6 ? 7 - zeroCnt - correct : 6;

    int min = 7 - correct < 6 ? 7 - correct : 6;
    answer.push_back(max);
    answer.push_back(min);

    return answer;
}

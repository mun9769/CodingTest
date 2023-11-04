#include <string>
#include <vector>
#include <iostream>
#define INF 2e9

using namespace std;

int prefixSum[1'000'005];

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    prefixSum[0] = sequence[0];
    
    for(int i=1; i<sequence.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + sequence[i];
    }
    int l = -1, r = 0;
    int sum = 0;
    int sz = INF;
    
    while(r < sequence.size()) {
        if(l != -1) sum = prefixSum[r] - prefixSum[l];
        else if(l == -1) sum = prefixSum[r];
        
        if(sum == k) {
            if(sz > r - l) {
                answer.clear();
                answer.push_back(l+1);
                answer.push_back(r);
                sz = r - l;
            }
            r++;
            l++;
        }
        else if(sum > k) {
            l++;
        }
        else if(sum < k) {
            r++;
        }
    }
    
    return answer;
}
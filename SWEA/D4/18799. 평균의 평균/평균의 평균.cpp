#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <numeric>
using namespace std;
using ii = pair<int, int>;
#define inf 987654321

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    double arr[10];
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        
        vector<double> avgs;
        
        for(int i=1; i<(1<<n); i++){
            
            vector<double> v;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) {
                    v.push_back(arr[j]);
                }
            }
            if(v.empty()) throw std::logic_error("");
            double avg = accumulate(v.begin(), v.end(), 0.0) / v.size();
            avgs.push_back(avg);
        }
        
        if(avgs.empty()) throw std::logic_error("");
        double avg_avg = accumulate(avgs.begin(), avgs.end(), 0.0) / avgs.size();
        
        cout <<"#"<<test_case<<' ';
        cout << std::fixed << std::setprecision(11) << avg_avg << endl;
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

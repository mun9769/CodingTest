#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        double sum = 0;
        for(int i=0; i<10; i++) {
            double num;
            cin >> num;
            sum += num;
        }
        cout << "#" << test_case << " " << round(sum / 10) << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
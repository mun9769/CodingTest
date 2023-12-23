#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;
using ii = pair<int, int>;
#define inf 987654321

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        double a, b, c;
        cin >> a >> b >> c;
        double left = b - (c-b);
        double mid = (a + c) / 2.0;
        double right = b + (b-a);
        
        double answer = inf;
        answer = min(answer, abs(mid - b));
        answer = min(answer, abs(left - a));
        answer = min(answer, abs(right - c));
        
        cout << "#"<<test_case<< ' ';
        cout << std::fixed << std::setprecision(1) << answer << endl;

    }
    return 0;
}

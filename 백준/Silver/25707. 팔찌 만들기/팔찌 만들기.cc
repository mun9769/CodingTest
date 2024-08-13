#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int ans;
    ans = 2 * (*v.rbegin() - *v.begin());
    cout << ans;
}
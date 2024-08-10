#include <iostream>
#include <vector>
using namespace std;
int n;
int main()
{
    cin >> n;
    int mx = 0;
    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        mx = max(mx, num);
    }
    cout << mx + n - 1;
}
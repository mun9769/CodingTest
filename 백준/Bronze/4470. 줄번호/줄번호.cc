#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
 
 
using namespace std;
 
typedef long long ll;
 
 int n;
 
 
int main()
{
    cin >> n;
    string s;
    cin.ignore();
    for(int i=1; i<=n; i++){
        getline(cin, s);
        cout << i << ". " << s <<endl;
    }
}
 

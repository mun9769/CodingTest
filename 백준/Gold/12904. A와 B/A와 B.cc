#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ii pair<int, int>

string x;
string y;

int main(int argc, const char * argv[]) {
    cin >> x >> y;
    
    while(y.size() > x.size()) {
        
        if(*y.rbegin() == 'A') {
            y.pop_back();
        }
        else {
            y.pop_back();
            reverse(y.begin(), y.end());
        }
    }
    if(x == y) cout << 1;
    else cout << 0;
    
}

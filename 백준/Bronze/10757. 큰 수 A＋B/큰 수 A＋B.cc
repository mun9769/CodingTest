#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a, b;

int main() {
  cin >> a >> b;
  if(a.size() > b.size()) swap(a, b);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int c = 0;
  int s = c;
  int mn = min(a.size(), b.size());
  int mx = max(a.size(), b.size());


  string ans = "";
  int i = 0;

  for(i=0; i<mx; i++){
    s = c;
    if(i<mn) {
      s += a[i] - '0';
    }
    s += b[i] - '0';

    if(s >= 10) {
      c = 1;
      s -= 10;
    }
    else {
      c = 0;
    }
    ans.push_back(s + '0');
  }
  if(c == 1) ans.push_back('1');

  reverse(ans.begin(), ans.end());
  cout << ans;
  
  
}

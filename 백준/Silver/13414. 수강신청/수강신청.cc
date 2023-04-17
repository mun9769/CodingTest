#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, int> um;
map<int, string> idToName;


int k, l;
string name;

#define ii pair<int, int>
#define INF 987987987

int id;


int main() {
  cin.tie(0) -> sync_with_stdio(0);

  cin >> k >> l;

  for(int i=0; i<l; i++){
    cin >> name;


    if(um.count(name)) {
      auto iter = um.find(name);
      string userName = (*iter).first;
      int userId = (*iter).second;
      idToName.erase(userId);
      idToName.insert({id, name});
      um[userName] = id;
      id++;
    }
    else {
      um.insert({name, id});
      idToName.insert({id, name});
      id++;
    }

  }

  int cnt = 0;

  for(auto ele : idToName){
    cout<< ele.second << '\n';
    cnt++;
    if(cnt >= k) break;
  }


}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define INF 987987987

int a, b, c;

int digit[20];

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  cin >> a >> b >> c;
  int mul = a * b * c;

  while(mul > 0){ // 해설은 무슨 변ㅜ?
    int one = mul % 10;
    mul /= 10;

    digit[one]++;
  }

  for(int i=0; i<10; i++)
    cout << digit[i] << endl;

}

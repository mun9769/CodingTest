#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;
#define ii pair<int, int>
#define INF 987654321
#define ll long long
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>

int gcd(ll x, ll y){
    if(y == 0){ return x; }
    else { return gcd(y, x%y); }
}


int n;

vector<iii> adj[12];
bool chk[12];

int a, b, p, q;

ll num[12];
ll den[12];


void bfs() {
	queue<int> qu;
	qu.push(0);
	chk[0] = true;
	while(qu.size()){

		int here = qu.front(); qu.pop();

		for(auto [count, p, q]: adj[here]){
      if(chk[count]) continue;
      num[count] *= num[here];
      den[count] *= den[here];

      num[count] *= q;
      den[count] *= p;

      int d = gcd(num[count], den[count]);
      num[count] /= d;
      den[count] /= d;

      qu.push(count);
      chk[count] = true;
		}
	}
}


int main(){
	cin.tie(0)-> ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> a >> b >> p >> q;
		int d = gcd(p, q);
		p = p / d; q = q / d;
		adj[a].push_back({b, p, q});
		adj[b].push_back({a, q, p});
	}

	fill(num, num+12, 1);
	fill(den, den+12, 1);


	bfs();

  ll tmp[12];
  for(int i=0; i<n; i++) tmp[i] = den[i];

  ll lcm = 1;

  for(int i=1; i<n; i++){
    lcm = (den[i-1] * den[i]) / gcd(den[i-1], den[i]);
    den[i] = lcm;
  }

  for(int i=0; i<n; i++) {
    num[i] *= (lcm / tmp[i]);
    cout << num[i] << ' ';
  }

	return 0;
}

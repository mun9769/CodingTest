#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


int n;
int student[1'000'004];
int supervisor, assistance;
long long answer;

int main() {
    cin.tie(0)-> sync_with_stdio(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> student[i];
    cin >> supervisor >> assistance;

    answer = n;
    for(int i=0; i<n; i++) {
        student[i] -= supervisor;
        if(student[i] <= 0) continue;

        if(student[i] % assistance == 0)
            answer += student[i] / assistance;
        else
            answer += student[i] / assistance + 1;
    }
    cout << answer;

}

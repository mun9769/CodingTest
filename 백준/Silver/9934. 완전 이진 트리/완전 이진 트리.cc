#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int K;
int node[2000];
vector<int> levels[12];

// go(0, treeCnt, 0
void go(int l, int r, int depth) {

    if (l == r) {
		levels[depth].push_back(node[l]);
        return;
    }

    int middle = (l + r) / 2;
    levels[depth].push_back(node[middle]);

    go(l, middle - 1, depth + 1);
    go(middle+1, r, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    int treeCnt = pow(2, K) - 1;

    for (int i = 0; i < treeCnt; i++) {
        cin >> node[i];
    }

    go(0, treeCnt - 1, 1);

    for (int i = 1; i <= K; i++) {
        for (int ele : levels[i]) {
            cout << ele << ' ';
        }
        cout << '\n';
    }

    return 0;
}

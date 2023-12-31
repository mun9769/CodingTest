#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
#define inf 987654321
#define off 50


int n1, m1, n2, m2;
int b1[200][200];
int b2[103][103];

int rot[52][52];
int answer = INT32_MAX;

void rotate() {
    for(int i=0; i<n2; i++) {
        for(int j=0; j<m2; j++) {
            rot[m2-1-j][i] = b2[i][j];
        }
    }

    swap(n2 ,m2);
    for(int i=0; i<n2; i++) {
        for(int j=0; j<m2; j++) {
            b2[i][j] = rot[i][j];
            // out bound에 더티값이 저장되어 있음을 유의하라.
        }
    }
}

void solve(int x, int y) {

    for(int i=x; i< x + n2; i++) {
        for(int j=y; j<y+m2; j++) {
            if(b2[i-x][j-y] and b1[i][j]) {
                return;
            }
        }
    }

    int min_x = min(x, 50);
    int max_x = max(50 + n1, x + n2);

    int min_y = min(y, 50);
    int max_y = max(50 + m1, y + m2);

    int area = (max_x - min_x) * (max_y - min_y);
    answer = min(answer, area);
}

int main()
{
    cin >> n1 >> m1;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<m1; j++) {
            char c; cin >> c;
            b1[i+off][j+off] = c-'0';
        }
    }
    cin >> n2 >> m2;
    for(int i=0; i<n2; i++) {
        for(int j=0; j<m2; j++) {
            char c; cin >> c;
            b2[i][j] = c-'0';
        }
    }

    for(int k=0; k<4; k++) {
        rotate();
        for(int i=0; i<off+n1; i++) {
            for(int j=0; j<off+m1; j++) {
                solve(i, j);
            }
        }
    }
    cout << answer;

}
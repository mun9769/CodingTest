#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
#define sz 22

int n;
int board[sz][sz];
int region[sz][sz];
map<int, int> score;

bool valid_range(int x, int y, int d1, int d2) {
    if(x+d1+d2 > n) return false;

    if(y-d1 < 1) return false;
    if(y+d2 > n) return false;

    return true;
}

void draw_line(int x, int y, int d1, int d2) {
    int mn = min(d1,d2);
    int _x = x+d1+d2;
    int _y = y-d1+d2;

    for(int i=1; i<x; i++) {
        for(int j=1; j<=n; j++) {
            if(j <= y) region[i][j] = 1;
            else region[i][j] = 2;
        }
    }
    for(int i=_x+1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(j < _y) region[i][j] = 3;
            else region[i][j] = 4;
        }
    }

    if(d1 > d2) {
        for(int i=x; i<=x+d2; i++) {
            int gap = i-x;
            int l = y - gap;
            int r = y + gap;
            for(int j = 1; j<=n; j++) {
                if(l <= j and j <= r) region[i][j] = 5;
                else if(j < l) region[i][j] = 1;
                else if(r < j) region[i][j] = 2;
            }
        }

        for(int i=_x; i>=_x-d2; i--) {
            int gap = _x-i;
            int l = _y - gap;
            int r = _y + gap;
            for(int j = 1; j<=n; j++) {
                if(l <= j and j <= r) region[i][j] = 5;
                else if(j < l) region[i][j] = 3;
                else if(r < j) region[i][j] = 4;
            }
        }

        for(int i=x+d2+1; i<=_x-d2-1; i++) {
            int gap = i - x;
            int l = y - gap;
            int r = y+d2-(gap-d2);
            for(int j=1; j<=n; j++) {
                if(l <= j and j <= r) region[i][j] = 5;
                else if(j < l) region[i][j] = 1;
                else if(r < j) region[i][j] = 4;
            }
        }
    }

    else if(d1 <= d2) {
        for(int i=x; i<x+d1; i++) {
            int gap = i-x;
            int l = y - gap;
            int r = y + gap;
            for(int j = 1; j<=n; j++) {
                if(l <= j and j <= r) region[i][j] = 5;
                else if(j < l) region[i][j] = 1;
                else if(r < j) region[i][j] = 2;
            }
        }

        for(int i=_x; i>_x-d1; i--) {
            int gap = _x-i;
            int l = _y - gap;
            int r = _y + gap;
            for(int j = 1; j<=n; j++) {
                if(l <= j and j <= r) region[i][j] = 5;
                else if(j < l) region[i][j] = 3;
                else if(r < j) region[i][j] = 4;
            }
        }

        for(int i=x+mn; i<=_x-mn; i++) {
            int gap = i - x;
            int l = y-d1+(gap-d1);
            int r = y+gap;
            for(int j=1; j<=n; j++) {
                if(l <= j and j <= r) region[i][j] = 5;
                else if(j < l) region[i][j] = 3;
                else if(r < j) region[i][j] = 2;
            }
        }
    }
}


void add_score_by_region() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            int id = region[i][j];
            score[id] += board[i][j];
        }
    }
}

int answer = INT32_MAX;

void divide_line() {

    for(int x=1; x<=n; x++) {
        for(int y=1; y<=n; y++) {

            for(int d1=1; d1<n; d1++) {
                for(int d2=1; d2<n; d2++) {
                    if(valid_range(x, y, d1, d2) == false) continue;
                    score.clear();

                    draw_line(x, y, d1, d2);

                    add_score_by_region();

                    int mx = 0;
                    int mn = INT32_MAX;
                    for(auto [key, value]: score) {
                        mx = max(mx, value);
                        mn = min(mn, value);
                    }

                    answer = min(answer, mx-mn);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
        cin >> board[i][j];

    divide_line();

    cout << answer;
}

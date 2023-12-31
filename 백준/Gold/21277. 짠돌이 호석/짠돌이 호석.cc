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
int answer;

void count_func(ii st) {
    bool possible[8] = { true, true, true, true, true, true, true, true, };

    for(int i = 0; i<n2; i++) {
        for(int j=0; j<m2; j++) {
            if(b1[st.first + i][st.second + j] and b2[i][j]) { possible[0] = false; }

            // if(b1[st.first + i][st.second - j] and b2[i][j]) { possible[1] = false; }

            if(b1[st.first - j][st.second + i] and b2[i][j]) { possible[2] = false; }

            // if(b1[st.first + j][st.second + i] and b2[i][j]) { possible[3] = false; }

            if(b1[st.first - i][st.second - j] and b2[i][j]) { possible[4] = false; }

            // if(b1[st.first - i][st.second + j] and b2[i][j]) { possible[5] = false; }

            if(b1[st.first + j][st.second - i] and b2[i][j]) { possible[6] = false; }

//            if(b1[st.first - j][st.second - i] and b2[i][j]) { possible[7] = false; }
        }
    }

    st.first -= off;
    st.second -= off;

    int area = INT32_MAX;
    int width;
    int height;

    if(possible[0]) {
        width  = max(m1, m2 + st.second);
        height = max(n1, n2 + st.first);
        area = min(area, width * height);
    }
//    if(possible[1]) {
//        width  = max(m2, m1 + m2 - st.second - 1);
//        height = max(n1, n2 + st.first);
//        area = min(area, width * height);
//    }

    if(possible[2]) {
        width  = max(m1, n2 + st.second);
        height = max(n1, n1 + m2 - st.first - 1);
        area = min(area, width * height);
    }
//    if(possible[3]) {
//        width  = max(m1, n2 + st.second);
//        height = max(n1, m2 + st.first);
//        area = min(area, width * height);
//    }

    if(possible[4]) {
        width  = max(m1, m1+m2 - st.second -1);
        height = max(n1, n1+n2 - st.first - 1);
        area = min(area, width * height);
    }
//    if(possible[5]) {
//        width  = max(m1, m2 + st.second);
//        height = max(n1, n1+n2 - st.first - 1);
//        area = min(area, width * height);
//    }

    if(possible[6]) {
        width  = max(m1, m1+n2 - st.second - 1);
        height = max(n1, m2 + st.first);
        area = min(area, width * height);
    }
//    if(possible[7]) {
//        width  = max(m1, m1+n2 - st.second - 1);
//        height = max(n1, n1+m2 - st.first - 1);
//        area = min(area, width * height);
//    }

    answer = min(area, answer);
}

int main()
{
    cin >> n1 >> m1;
    for(int i=0; i<n1; i++) {
        string s; cin >> s;
        for(int j=0; j<m1; j++) {
            b1[i+off][j+off] = s[j] - '0';
        }
    }
    cin >> n2 >> m2;
    for(int i=0; i<n2; i++) {
        string s; cin >> s;
        for(int j=0; j<m2; j++) {
            b2[i][j] = s[j] - '0';
        }
    }
    int ans1 = (n1+n2) * max(m1, m2);
    int ans2 = (m1+m2) * max(n1, n2);
    answer = min(ans1, ans2);

    for(int i=off; i<off+n1; i++) for(int j=off; j<off+m1; j++) {
        count_func({i, j});
    }

    cout << answer;

}
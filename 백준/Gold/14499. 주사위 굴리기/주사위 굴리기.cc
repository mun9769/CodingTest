#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

enum Side {
    up, down, north, east, south, west = 5
};

enum Query {
    go_east = 1, go_west = 2, go_north = 3, go_south = 4,
};
ii offsets(Query q) {
    if(q == go_east) return {0, 1};
    if(q == go_west) return {0, -1};
    if(q == go_north) return {-1, 0};
    if(q == go_south) return {1, 0};

    throw std::logic_error("");
}

int n, m;
int k;
int board[22][22];
vector<Query> queries;

class Dice {
public:
    map<Side, int> rectangle;
    int x, y;

    void go(int nx, int ny, Query query) {
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) return;

        if(query == go_south) {
            if(board[nx][ny] == 0) { board[nx][ny] = rectangle[south]; }
            else { rectangle[south] = board[nx][ny]; board[nx][ny] = 0; }

            swap(rectangle[down], rectangle[south]);
            swap(rectangle[south], rectangle[up]);
            swap(rectangle[up], rectangle[north]);
        }
        else if(query == go_north) {
            if(board[nx][ny] == 0) { board[nx][ny] = rectangle[north]; }
            else { rectangle[north] = board[nx][ny]; board[nx][ny] = 0; }

            swap(rectangle[down], rectangle[north]);
            swap(rectangle[north], rectangle[up]);
            swap(rectangle[up], rectangle[south]);
        }
        else if(query == go_east) {
            if(board[nx][ny] == 0) { board[nx][ny] = rectangle[east]; }
            else { rectangle[east] = board[nx][ny]; board[nx][ny] = 0; }

            swap(rectangle[down], rectangle[east]);
            swap(rectangle[east], rectangle[up]);
            swap(rectangle[up], rectangle[west]);


        }
        else if(query == go_west) {
            if(board[nx][ny] == 0) { board[nx][ny] = rectangle[west]; }
            else { rectangle[west] = board[nx][ny]; board[nx][ny] = 0; }

            swap(rectangle[down], rectangle[west]);
            swap(rectangle[west], rectangle[up]);
            swap(rectangle[up], rectangle[east]);
        }

        x = nx; y = ny;
        cout << rectangle[up] << '\n';
    }
};

Dice dice;

void input_value() {
    cin >> n >> m >> dice.x >> dice.y >> k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> board[i][j];

    for(int i=0; i<k; i++) {
        int q; cin >> q;
        queries.push_back(static_cast<Query>(q));
    }

}

int main() {
    input_value();

    for(Query query: queries) {
        int nx = dice.x + offsets(query).first;
        int ny = dice.y + offsets(query).second;

        dice.go(nx, ny, query);
    }

}

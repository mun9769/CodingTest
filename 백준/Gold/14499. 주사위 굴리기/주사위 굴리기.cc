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
Side toSide(Query q) {
    if(q == go_east) return Side::east;
    if(q == go_west) return Side::west;
    if(q == go_north) return Side::north;
    if(q == go_south) return Side::south;

    throw std::logic_error("");
}
Side toCounter(Side s) {
    if(s == north) return Side::south;
    if(s == south) return Side::north;
    if(s == west) return Side::east;
    if(s == east) return Side::west;
    if(s == up) return Side::down;
    if(s == down) return Side::up;
    
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

    void real_go(Query q) {
    }

    void go(int nx, int ny, Query query) {
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) return;
        Side goal = toSide(query);
        Side counter = toCounter(goal);

        if(board[nx][ny] == 0) { board[nx][ny] = rectangle[goal]; }
        else { rectangle[goal] = board[nx][ny]; board[nx][ny] = 0; }

        swap(rectangle[down], rectangle[goal]);
        swap(rectangle[goal], rectangle[up]);
        swap(rectangle[up], rectangle[counter]);
        
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

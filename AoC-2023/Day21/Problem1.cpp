#include <bits/stdc++.h>
using namespace std;

int M,N;
vector<string> grid;
const vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

bool in(int x, int y){
    return x>=0 && y>=0 && x < M && y < N;
}

int countGardenPlots(int steps, int sx, int sy){
    set<pair<int,int>> curr, next;
    curr.insert({sx, sy});

    for(int step = 0; step < steps; step++){
        next.clear();

        for(auto [x, y] : curr){
            for(auto [dx, dy] : dirs){
                int nx = x + dx;
                int ny = y + dy;

                if(in(nx, ny) && grid[nx][ny] != '#'){
                    next.insert({nx, ny});
                }
            }
        }
        curr = next;
    }

    return curr.size();
}


void solve() {
    string line;
    while(getline(cin, line)) grid.push_back(line);

    int sx,sy;
    M = grid.size(), N = grid[0].size();

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 'S'){
                sx = i, sy = j;
            }
        }
    }

    int ans = countGardenPlots(64, sx, sy);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
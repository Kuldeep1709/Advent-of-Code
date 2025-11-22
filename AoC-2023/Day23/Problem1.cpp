#include <bits/stdc++.h>
using namespace std;

int M,N;
vector<string> grid;
vector<vector<bool>> seen;
const vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

bool in(int x, int y){
    return x>=0 && y>=0 && x < M && y < N;
}

void dfs(int x, int y, int ex, int ey, int curr, int &ans){
    if(x == ex && y == ey){
        ans = max(ans, curr);
        return;
    }

    if(not in(x, y) || grid[x][y] == '#' || seen[x][y]) return;

    seen[x][y] = true;

    if(grid[x][y] == '.'){
        for(auto [dx, dy]: dirs){
            dfs(x+dx, y+dy, ex, ey, curr+1, ans);
        }
    }
    else if(grid[x][y] == '^') dfs(x-1, y, ex, ey, curr+1, ans);
    else if(grid[x][y] == '>') dfs(x, y+1, ex, ey, curr+1, ans);
    else if(grid[x][y] == 'v') dfs(x+1, y, ex, ey, curr+1, ans);
    else if(grid[x][y] == '<') dfs(x, y-1, ex, ey, curr+1, ans);

    seen[x][y] = false;
}

void solve() {
    string line;
    while(getline(cin, line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();
    seen.assign(M, vector<bool>(N, false));

    int sx = 0, sy = 0, ex = M-1, ey = N-1; 

    for(int j=0;j<N;j++){
        if(grid[0][j] == '.') sy = j;
        if(grid[M-1][j] == '.') ey = j;
    }

    int ans = 0;
    dfs(sx, sy, ex, ey, 0, ans);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
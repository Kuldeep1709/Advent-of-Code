#include <bits/stdc++.h>
using namespace std;

const unordered_map<char, vector<pair<int,int>>> dirs = 
{   
    {'|', {{1,0}, {-1,0}}}, 
    {'-', {{0,1}, {0,-1}}},
    {'L', {{-1,0}, {0,1}}},
    {'J', {{-1,0}, {0,-1}}},
    {'7', {{1,0}, {0,-1}}},
    {'F', {{1,0}, {0,1}}}
};

int M, N;
int cycle = 0;
vector<string> grid;
vector<vector<bool>> vis;

bool in(int x, int y) { return x>=0 && y >=0 && x < M && y < N;}

void dfs(int x, int y, int len = 1){
    if(grid[x][y] == 'S'){
        cycle = max(cycle, len);
        return;
    }
    if(grid[x][y] == '.' || vis[x][y]) return;

    vis[x][y] = true;
    const vector<pair<int,int>> arr = dirs.at(grid[x][y]);

    for(auto &next: arr){
        int dx = next.first, dy = next.second;
        if(in(x+dx, y+dy)) dfs(x+dx, y+dy, len+1);
    }

    vis[x][y] = false;
}

void solve() {
    string line;
    while(getline(cin, line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();

    int sx, sy;
    bool found = false;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 'S'){
                sx = i, sy = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }

    vis.resize(M, vector<bool> (N, false));

    if(in(sx+1, sy)){
        const string next = "|LJ";
        if(next.find(grid[sx+1][sy]) != std::string::npos) dfs(sx+1, sy); // down
    }
    if(in(sx, sy+1)){
        const string next = "-7J";
        if(next.find(grid[sx][sy+1]) != std::string::npos) dfs(sx, sy+1); // right
    }
    if(in(sx-1, sy)){
        const string next = "|7F";
        if(next.find(grid[sx-1][sy]) != std::string::npos) dfs(sx-1, sy); // up
    }
    if(in(sx, sy-1)){
        const string next = "-LF";
        if(next.find(grid[sx][sy-1]) != std::string::npos) dfs(sx, sy-1); // left
    }

    int ans = cycle/2;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
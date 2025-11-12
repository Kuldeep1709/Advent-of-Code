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
int area = 0;
vector<string> grid;
vector<vector<bool>> vis;

bool in(int x, int y) { return x>=0 && y >=0 && x < M && y < N;}

void updateArea(){
    int curr = 0;
    const string pipe = "|LJ";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;

            int cross = 0;
            for (int k = j; k < N; k++) {
                if(!vis[i][k]) continue;
                if (pipe.find(grid[i][k]) != std::string::npos) cross++;
            }

            if (cross % 2 != 0) curr++;
        }
    }
    area = max(area, curr);
}

void dfs(int x, int y, int px, int py, int len = 1){
    if(grid[x][y] == 'S'){
        updateArea();
        return;
    }
    if(grid[x][y] == '.' || vis[x][y]) return;

    vis[x][y] = true;
    const vector<pair<int,int>> arr = dirs.at(grid[x][y]);

    for(auto &next: arr){
        int dx = next.first, dy = next.second;
        if(x+dx == px && x+dy == py) continue;
        if(in(x+dx, y+dy)) dfs(x+dx, y+dy, px, py, len+1);
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
    vis[sx][sy] = true;

    if(in(sx+1, sy)){
        const string next = "|LJ";
        if(next.find(grid[sx+1][sy]) != std::string::npos) dfs(sx+1, sy, -1, -1); // down
    }
    if(in(sx, sy+1)){
        const string next = "-7J";
        if(next.find(grid[sx][sy+1]) != std::string::npos) dfs(sx, sy+1, -1, -1); // right
    }
    if(in(sx-1, sy)){
        const string next = "|7F";
        if(next.find(grid[sx-1][sy]) != std::string::npos) dfs(sx-1, sy, -1, -1); // up
    }
    if(in(sx, sy-1)){
        const string next = "-LF";
        if(next.find(grid[sx][sy-1]) != std::string::npos) dfs(sx, sy-1, -1, -1); // left
    }

    cout << area << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
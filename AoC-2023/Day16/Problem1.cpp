#include <bits/stdc++.h>
using namespace std;

int M,N;
vector<string> grid;
vector<vector<vector<bool>>> vis;
const map<pair<int,int>, int> dirIndex = 
{
    {{0,1}, 0}, // >
    {{0,-1}, 1}, // <
    {{1,0}, 2}, // v
    {{-1,0}, 3} // ^
};

bool in(int x, int y){
    return x>=0 && y>=0 && x < M && y < N;
}

void energize(int x, int y, int dx = 0, int dy = 1){
    int idx = dirIndex.at({dx, dy});

    if(not in(x,y) || vis[x][y][idx]) return;

    vis[x][y][idx] = true;

    char curr = grid[x][y];

    if(curr == '.') energize(x+dx,y+dy, dx,dy);
    else if(curr == '|'){
        if(dx == 0){
            energize(x-1, y, -1, 0);
            energize(x+1, y, 1, 0);
        }
        else energize(x+dx,y+dy, dx,dy);
    }
    else if(curr == '-'){
        if(dy == 0){
            energize(x, y-1, 0, -1);
            energize(x, y+1, 0, 1);
        }
        else energize(x+dx,y+dy, dx,dy);
    }
    else if(curr == '/'){
        if(idx == 0) energize(x-1,y, -1,0);
        else if(idx == 1) energize(x+1,y, 1,0);
        else if(idx == 2) energize(x,y-1, 0,-1);
        else if(idx == 3) energize(x,y+1, 0,1);
    }
    else{ // we can use '\\' to check \ char in cpp
        if(idx == 0) energize(x+1,y, 1,0);
        else if(idx == 1) energize(x-1,y, -1,0);
        else if(idx == 2) energize(x,y+1, 0, 1);
        else if(idx == 3) energize(x,y-1, 0, -1);
    }
}

void solve() {
    string line;
    while(getline(cin, line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();
    vis.resize(M, vector<vector<bool>>(N, vector<bool>(4, false)));

    energize(0,0);

    int ans = 0;
    for(const auto &v: vis){
        for(const auto &b: v){
            ans += (b[0] | b[1] | b[2] | b[3]);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
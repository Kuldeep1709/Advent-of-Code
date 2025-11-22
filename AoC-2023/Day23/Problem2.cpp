#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>

int M,N;
vector<string> grid;
vector<vector<int>> dp;
vector<vector<bool>> seen;
const map<char, vector<pair<int,int>>> dirs = 
{
    {'^', {{-1,0}}},
    {'>', {{0,1}}},
    {'v', {{1,0}}},
    {'<', {{0,-1}}},
    {'.', {{-1,0}, {0, -1}, {1,0}, {0,1}}}
};

bool in(int x, int y){
    return x>=0 && y>=0 && x < M && y < N;
}

int dfs(int x, int y, int ex, int ey, map<pii, vector<vi>> &adj){
    if(x == ex && y == ey) return 0;

    int ans = -1e9;
    if(seen[x][y]) return ans;
    seen[x][y] = true;

    for(auto &next: adj[{x,y}]){
        ans = max(ans, next[2] + dfs(next[0], next[1], ex, ey, adj));
    }

    seen[x][y] = false;
    return ans;
}

map<pii, vector<vi>> contractEgdesAdj(int sx, int sy, int ex, int ey){
    set<pair<int,int>> points = {{sx, sy}, {ex, ey}};
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == '#') continue;
            int neigh = 0;
            for(auto &[di, dj]: dirs.at('.')){
                if(in(i+di, j+dj) && grid[i+di][j+dj] != '#'){
                    neigh++;
                }
            }
            if(neigh > 2) points.insert({i,j});
        }
    }

    map<pii, vector<vi>> adj;

    for(auto &point: points){
        stack<vi> st;
        sx = point.first, sy = point.second;
        st.push({0, sx, sy});
        map<pii, bool> vis;
        vis[{sx, sy}] = true;

        while(!st.empty()){
            vi curr = st.top();st.pop();
            int n = curr[0], x = curr[1], y = curr[2];

            if(n != 0 && points.find({x,y}) != points.end()){
                adj[{sx,sy}].push_back({x,y,n});
                continue;
            }
            
            for(auto &[dx, dy]: dirs.at('.')){
                int nx = x + dx, ny = y + dy;

                if(in(nx, ny) && grid[nx][ny] != '#' && !vis.count({nx, ny})){
                    st.push({n+1, nx, ny});
                    vis[{nx, ny}] = true;
                }
            }
        }
    }
    return adj;
}

void solve() {
    string line;
    while(getline(cin, line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();
    dp.assign(M, vector<int>(N, -1));
    seen.assign(M, vector<bool>(N, false));

    int sx = 0, sy = 0, ex = M-1, ey = N-1; 

    for(int j=0;j<N;j++){
        if(grid[0][j] == '.') sy = j;
        if(grid[M-1][j] == '.') ey = j;
    }

    map<pii, vector<vi>> adj = contractEgdesAdj(sx, sy, ex, ey);

    int ans = dfs(sx, sy, ex, ey, adj);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
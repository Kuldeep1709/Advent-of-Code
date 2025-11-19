#include <bits/stdc++.h>
using namespace std;

int M, N;
const vector<vector<int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

bool in(int x, int y){
    return x>=0 && y>=0 && x < N && y < M;
}

int calculateInnerPoints(const vector<string> &grid, const int M, const int N){
    int outsideArea = 0;

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(N, vector<bool> (M, false));
    q.push({0,0});

    while(not q.empty()){
        const pair<int,int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        if(in(x,y) && !vis[x][y] && grid[x][y] != '#'){
            vis[x][y] = true;
            outsideArea++;
            for(auto dir: dirs){
                const int dx = dir[0], dy = dir[1];

                if(in(x+dx, y+dy)){
                    q.push({x+dx, y+dy});
                }
            }
        }
    }

    return N*M - outsideArea;
}

void solve() {
    string line;
    M = 1, N = 1;
    int x = 1, y = 1;
    vector<pair<char,int>> instructions;

    while(getline(cin, line)){
        const char dir = line[0];
        int idx = 2;
        while('0' <= line[idx] && line[idx] <= '9') idx++;

        const int len = stoi(line.substr(2,idx-1));
        const string color = line.substr(idx+1);

        instructions.push_back({dir, len});

        if(dir == 'L') x -= len;
        else if(dir == 'R') x += len;
        else if(dir == 'D') y += len;
        else y -= len;

        M = max(M, abs(x));
        N = max(N, abs(y));
    }

    int row = N, col = M;

    M = (M<<1) + 1;
    N = (N<<1) + 1;

    vector<string> grid(N);
    const string dots(M, '.');
    for(int i=0;i<N;i++) grid[i] = dots;

    for(const auto &instruction: instructions){
        const char dir = instruction.first;
        const int len = instruction.second;

        int curr = len;
        if(dir == 'L') while(curr--) grid[row][--col] = '#';
        else if(dir == 'R') while(curr--) grid[row][++col] = '#';
        else if(dir == 'D') while(curr--) grid[++row][col] = '#';
        else while(curr--) grid[--row][col] = '#';
    }

    int ans = calculateInnerPoints(grid, M, N);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
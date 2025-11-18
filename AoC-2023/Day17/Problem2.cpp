#include <bits/stdc++.h>
using namespace std;

int M, N;
#define vi vector<int>
const vector<vector<int>> dirs = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

bool in(int x, int y){
    return x>=0 && y>=0 && x < M && y < N;
}

void solve() {
    string line;
    vector<string> grid;
    while(getline(cin, line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();

    set<vi> seen;
    priority_queue<vi, vector<vi>, greater<vi>> pq;

    // heatLoss, x, y, dx, dy, steps left in single direction
    if(in(1,0)) pq.push({0, 1,0,1,0, 9});
    if(in(0,1)) pq.push({0, 0,1,0,1, 9});
    
    while(not pq.empty()){
        const vi curr = pq.top();
        pq.pop();

        const int heatLoss = curr[0], x = curr[1], y = curr[2];
        const int dx = curr[3], dy = curr[4], stepsLeft = curr[5];

        if(x == M-1 && y == N-1 && stepsLeft <= 6){
            cout << heatLoss + (grid[x][y] - '0') << "\n";
            break;
        }

        const vi state = {x,y,dx,dy,stepsLeft};
        if(seen.find(state) != seen.end()) continue;
        seen.insert(state);

        if(stepsLeft <= 6){
            for(const vi &dir: dirs){
                int da = dir[0], db = dir[1];

                if((da == dx && db == dy) || (da == -dx && db == -dy)) continue;

                if(in(x+da, y+db)){
                    pq.push({heatLoss + (grid[x][y] - '0'), x+da, y+db, da, db, 9});
                }
            }
        }

        if(stepsLeft > 0 && in(x+dx, y+dy)){
            pq.push({heatLoss + (grid[x][y] - '0'), x+dx, y+dy, dx, dy, stepsLeft-1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
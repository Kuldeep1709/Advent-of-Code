#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

void addSummary(const vector<string> &grid){
    int M = grid.size(), N = grid[0].size();

    // row
    for(int row=1;row<M;row++){
        int cnt = 0, up = row - 1, down = row;
        while(up >=0 && down < M){
            if(grid[up] != grid[down]) cnt++;
            up--;
            down++;
        }
        if(cnt == 0) ans += 1LL*100*row;
    }

    // col
    for(int col=1;col<N;col++){
        int cnt = 0, left = col-1, right = col;

        while(left >=0 && right < N){
            bool no = false;
            for(int row=0;row<M;row++){
                if(grid[row][left] != grid[row][right]){
                    no = true;
                    break;
                }
            }
            if(no) cnt++;
            left--;
            right++;
        }
        if(cnt == 0) ans += 1LL*col;
    }
}

void solve() {
    string line;
    vector<string> grid;

    while(getline(cin,line)){
        if(line.empty()) addSummary(grid), grid.clear();
        else grid.push_back(line);
    }
    addSummary(grid);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string line;
    vector<string> grid;
    while(getline(cin,line)) grid.push_back(line);
    
    const int M = grid.size(), N = grid[0].size();

    long long ans = 0;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 'O'){
                int k = i;
                while(k > 0){
                    if(grid[k-1][j] != '.') break;
                    swap(grid[k-1][j], grid[k][j]);
                    k--;
                }
                ans += (M-k);
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
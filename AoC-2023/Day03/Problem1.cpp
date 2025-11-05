#include <bits/stdc++.h>
using namespace std;

int N = 140, M;
vector<vector<int>> dirs = {{1,0},{1,1},{1,-1},{-1,0}, {-1,1},{-1,-1},{0,1},{0,-1}};

bool in(int x,int y){
    return x>=0 && y>= 0 && x < N && y < M;
}

void solve() {
    vector<string> grid;

    for (int line=1;line<=N;line++) {
        string s;
        getline(cin, s);

        grid.push_back(s);
    }

    long long ans = 0;
    M = grid[0].size();

    map<char,bool> digits;
    for(char c = '0'; c <= '9'; c++) digits[c] = true;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(digits.count(grid[i][j])){
                string num;
                bool part = false;

                while(j < M && digits.count(grid[i][j])){
                    num.push_back(grid[i][j]);

                    for(auto dir: dirs){
                        int x = i+dir[0], y = j+dir[1];
                        if(in(x,y) && !(digits.count(grid[x][y])) && grid[x][y] != '.') part = true;
                    }

                    j++;
                }

                if(part) ans += stoi(num);
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


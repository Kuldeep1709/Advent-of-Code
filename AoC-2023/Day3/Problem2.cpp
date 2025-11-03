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

    M = grid[0].size();

    map<char,bool> digits;
    for(char c = '0'; c <= '9'; c++) digits[c] = true;

    map<pair<int,int>,vector<int>> gears;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(digits.count(grid[i][j])){
                string num;
                bool part = false;
                set<pair<int,int>> pairs;

                while(j < M && digits.count(grid[i][j])){
                    num.push_back(grid[i][j]);

                    for(auto dir: dirs){
                        int x = i+dir[0], y = j+dir[1];
                        if(in(x,y) && grid[x][y] == '*'){
                            pairs.insert({x,y});
                        }
                    }

                    j++;
                }

                int val = stoi(num);

                for(const auto &p: pairs) gears[p].push_back(val);
            }
        }
    }
    
    long long ans = 0;
    for(const auto &p: gears){
        if(p.second.size() == 2){
            ans += (p.second[0] * p.second[1]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}


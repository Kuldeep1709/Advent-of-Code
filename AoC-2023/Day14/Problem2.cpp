#include <bits/stdc++.h>
using namespace std;

int M,N;
vector<string> grid;
map<vector<string>, int> visited;
const int cycles = 1e9;

void tiltNorth(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 'O'){
                int k = i;
                while(k > 0 && grid[k-1][j] == '.'){
                    swap(grid[k-1][j], grid[k][j]);
                    k--;
                }
            }
        }
    }
}

void tiltSouth(){
    for(int i=M-1;i>=0;i--){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 'O'){
                int k = i+1;
                while(k < M && grid[k][j] == '.'){
                    swap(grid[k-1][j], grid[k][j]);
                    k++;
                }
            }
        }
    }
}

void tiltWest(){
    for(int j=0;j<N;j++){
        for(int i=0;i<M;i++){
            if(grid[i][j] == 'O'){
                int k = j;
                while(k > 0 && grid[i][k-1] == '.'){
                    swap(grid[i][k-1], grid[i][k]);
                    k--;
                }
            }
        }
    }
}

void tiltEast(){
    for(int j=N-1;j>=0;j--){
        for(int i=0;i<M;i++){
            if(grid[i][j] == 'O'){
                int k = j+1;
                while(k < N && grid[i][k] == '.'){
                    swap(grid[i][k-1], grid[i][k]);
                    k++;
                }
            }
        }
    }
}

long long northLoad(){
    long long load = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 'O'){
                load += (M-i);
            }
        }
    }
    return load;
}

void solve() {
    string line;
    while(getline(cin,line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();

    int count = 0;
    visited[grid] = 0;

    while(count < cycles){
        tiltNorth();
        tiltWest();
        tiltSouth();
        tiltEast();

        count++;

        if(visited.count(grid)) break;
        visited[grid] = count;
    }
    int leftCycles = 0, len = count - visited[grid];
    if(count < cycles) leftCycles = (cycles - visited[grid]) % len;

    while(leftCycles--){
        tiltNorth();
        tiltWest();
        tiltSouth();
        tiltEast();
    }

    cout << northLoad() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
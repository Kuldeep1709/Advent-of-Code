#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<int> emptyRows, emptyCols;

#define all(x) (x).begin(), (x).end()

int shortestDist(const vector<int> &g1, const vector<int> &g2){
    int x1 = g1[0], y1 = g1[1], x2 = g2[0], y2 = g2[1];

    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);

    int extraRows = upper_bound(all(emptyRows), x2) - lower_bound(all(emptyRows), x1);
    int extraCols = upper_bound(all(emptyCols), y2) - lower_bound(all(emptyCols), y1);

    return abs(x2-x1) + abs(y2-y1) + extraCols + extraRows;
}

void solve() {
    string line;
    vector<string> grid;
    while(getline(cin, line)) grid.push_back(line);

    M = grid.size(), N = grid[0].size();

    vector<vector<int>> galaxies;

    for(int i=0;i<M;i++){
        bool isEmpty = true;
        for(int j=0;j<N;j++){
            if(grid[i][j] == '#'){
                isEmpty = false;
                galaxies.push_back({i,j});
            }
        }
        if(isEmpty) emptyRows.push_back(i);
    }

    for(int j=0;j<N;j++){
        bool isEmpty = true;
        for(int i=0;i<M;i++){
            if(grid[i][j] == '#'){
                isEmpty = false;
                break;
            }
        }
        if(isEmpty) emptyCols.push_back(j);
    }

    int n = galaxies.size(), totalDistance = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            totalDistance += shortestDist(galaxies[i], galaxies[j]);
        }
    }

    cout << totalDistance << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
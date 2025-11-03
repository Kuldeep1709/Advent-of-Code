#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

bool in(int x, int y, int n = 140) {
    return x >= 0 && y >= 0 && x < n && y < n;
}


ull bfs(vector<string> &arr, vector<vector<bool>> &vis, int i, int j) {
    ull ans = 0,cnt=0;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true; 

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cnt++;
        
        for (auto d : dir) {
            int nx = x + d[0], ny = y + d[1];
            if (in(nx, ny, arr.size())) {
                if (arr[nx][ny] == arr[x][y] && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                } 
                else if (arr[nx][ny] != arr[x][y]) ans++; 
            } 
            else ans++; 
        }
    }
    return ans*cnt;
}

int main() {
    int n = 140; 
    vector<string> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    ull ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                ans += bfs(arr, vis, i, j);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
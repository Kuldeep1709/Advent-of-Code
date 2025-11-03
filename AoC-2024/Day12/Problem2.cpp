#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define n 140

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool sides_visited(int x,int y,int i,map<pair<int,int>,vector<int>> &m){
	if(i&1){
		if(in(x-1,y)){
			if(m.find({x-1,y})!=m.end()) for(int z:m[{x-1,y}]) if(z==i) return true;
		}

		if(in(x+1,y)){
			if(m.find({x+1,y})!=m.end()) for(int z:m[{x+1,y}]) if(z==i) return true;
		}
	}
	else{
		if(in(x,y-1)){
			if(m.find({x,y-1})!=m.end()) for(int z:m[{x,y-1}]) if(z==i) return true;
		}

		if(in(x,y+1)){
			if(m.find({x,y+1})!=m.end()) for(int z:m[{x,y+1}]) if(z==i) return true;
		}
	}
	return false;
}

ull bfs(vector<string> &arr, vector<vector<bool>> &vis, int i, int j) {
    ull sides = 0,cnt=0;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true; 
    map<pair<int,int>,vector<int>> m;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cnt++;
        
        for(int i=0;i<4;i++){
        	vector<int> d=dir[i];
            int nx = x + d[0], ny = y + d[1];
            if (in(nx, ny)) {
                if (arr[nx][ny] == arr[x][y] && !vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
                else if(arr[nx][ny] != arr[x][y]){
                	if(!sides_visited(x,y,i,m)) sides++;
                	m[{x,y}].push_back(i);
                }
            } 
            else{
            	if(!sides_visited(x,y,i,m)) sides++;
            	m[{x,y}].push_back(i);
            }
        }
    }
    // cout<<cnt<<" "<<sides<<"\n";
    return sides*cnt;
}

int main() {

    vector<string> arr(n);

    for (int i=0;i<n;i++) cin>>arr[i];
    
    ull ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                ans += bfs(arr, vis, i, j);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
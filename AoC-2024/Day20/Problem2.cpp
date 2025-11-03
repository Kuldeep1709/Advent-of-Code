#include <bits/stdc++.h>
using namespace std;

#define n 141

bool in(int x,int y){
	return x>=0 && y>=0 && x<n && y<n;
}

int cheat20ps(const vector<vector<int>> &dis){
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dis[i][j]==-1) continue;
			vector<vector<bool>> vis(n,vector<bool>(n,false));
			for(int sec=2;sec<=20;sec++){
				for(int di=0;di<=sec;di++){
					int dj=sec-di;
					vector<vector<int>> move={{i+di,j+dj},{i+di,j-dj},{i-di,j+dj},{i-di,j-dj}};
					for(auto ele:move){
						int x=ele[0],y=ele[1];
						if(in(x,y) && dis[x][y]!=-1 && !vis[x][y] && dis[i][j]>=dis[x][y]+100+sec) ans++,vis[x][y]=true;
					}
				}
			}
		}
	}
	return ans;
}

void bfs(vector<vector<int>> &dis,const vector<string> &arr,int i,int j){
	queue<vector<int>> q; 
	vector<vector<int>> move={{1,0},{0,1},{-1,0},{0,-1}};
	q.push({i,j});
	dis[i][j]=0;

	while(!q.empty()){
		vector<int> ele=q.front();
		q.pop();
		int x=ele[0],y=ele[1];

		for(vector<int> mv:move){
			int dx=mv[0],dy=mv[1];
			if(in(x+dx,y+dy) && dis[x+dx][y+dy]==-1 && arr[x+dx][y+dy]!='#'){
				dis[x+dx][y+dy]=1+dis[x][y];
				q.push({x+dx,y+dy});
			}
		}
	}
	return;
}

int main(){
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	int x=0,y=0,ex=0,ey=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='S') x=i,y=j;
			if(arr[i][j]=='E') ex=i,ey=j;
		}
	}

	vector<vector<int>> dis(n,vector<int>(n,-1));

	bfs(dis,arr,x,y);

	int prev=dis[ex][ey]; // Answer without Cheat

	int ans=cheat20ps(dis); // Answer with 20 Pico Second Cheat

	cout<<ans<<"\n";
	
	return 0;
}
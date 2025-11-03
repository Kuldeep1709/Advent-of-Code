#include <bits/stdc++.h>
using namespace std;

#define n 141

bool in(int x,int y){
	return x>0 && y>0 && x<n && y<n;
}

int cheat(int i,int j,const vector<vector<int>> &dis){
	queue<vector<int>> q;
	vector<vector<int>> move={{1,0},{0,1},{-1,0},{0,-1}};
	vector<vector<bool>> vis(n,vector<bool> (n,false));

	q.push({i,j});
	vis[i][j]=true;
	int ans=0;

	while(!q.empty()){
		vector<int> ele=q.front();
		q.pop();
		int x=ele[0],y=ele[1];

		for(int i=0;i<4;i++){
			int dx=move[i][0],dy=move[i][1];
			if(in(x+dx,y+dy) && !vis[x+dx][y+dy]){
				if(dis[x+dx][y+dy]!=-1) q.push({x+dx,y+dy}),vis[x+dx][y+dy]=true;
				else{
					int nxt=dis[x][y]+102;
					int dx1=move[(i+1)%4][0],dy1=move[(i+1)%4][1];
					int dx2=move[(i+3)%4][0],dy2=move[(i+3)%4][1];

					if((in(x+2*dx,y+2*dy) && dis[x+2*dx][y+2*dy]>=nxt) || (in(x+dx1,y+dy1) && dis[x+dx1][y+dy1]>=nxt) || (in(x+dx2,y+dy2) && dis[x+dx2][y+dy2]>=nxt)) ans++;
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

	int ans=cheat(x,y,dis); // Answer With 2 Pico Second 1 Cheat

	cout<<ans<<"\n";
	
	return 0;
}

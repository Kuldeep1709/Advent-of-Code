#include <bits/stdc++.h>
using namespace std;

#define n 141
#define inf (1e9)
#define piv pair<int,vector<int>>

bool in(int x,int y){
	return x>0 && y>0 && x<n && y<n;
}

int dijkstra(vector<string> &arr,int i,int j,int dir,vector<vector<int>> &dis){

	priority_queue<piv,vector<piv>,greater<piv>> pq;
	vector<vector<int>> move={{0,1},{1,0},{0,-1},{-1,0}};
	vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(n,vector<bool>(4,false)));

	pq.push({0,{i,j,0}});
	pq.push({0,{i,j,1}});
	dis[i][j]=0;

	while(!pq.empty()){

		piv ele=pq.top();
		int x=ele.second[0],y=ele.second[1];
		int wt=ele.first,mv=ele.second[2];
		pq.pop();
		vis[x][y][mv]=true;
		if(arr[x][y]=='E') return wt;

		for(int i=0;i<4;i++){
			int p=x+move[i][0],q=y+move[i][1];
			if(!in(p,q) || arr[p][q]=='#' || vis[p][q][i]) continue;
			int cost=1;
			if(mv!=i) cost=1001;
			
			if(dis[x][y]+cost < dis[p][q]){
				dis[p][q]=dis[x][y]+cost;
				pq.push({dis[p][q],{p,q,i}});
			}
			
		}
	}

	return dis[1][n-2]; // Temporary return

}

int bfs(vector<vector<int>> &dis,int target){
	queue<vector<int>> q; 
	vector<vector<bool>> vis(n,vector<bool>(n,false));
	vector<vector<int>> move={{0,1},{1,0},{0,-1},{-1,0}};

	if(dis[2][n-2]==target-1){
		q.push({2,n-2,dis[1][n-2]-1,1});
	}
	if(dis[1][n-3]==target-1){
		q.push({1,n-3,2,dis[1][n-1]-1,2});
	}

	int ans=1;

	while(!q.empty()){
		vector<int> ele=q.front();
		q.pop();

		int x=ele[0],y=ele[1],d=ele[2],mv=ele[3];
		if(!vis[x][y]) ans++,vis[x][y]=true;

		int a=x+move[mv][0],b=y+move[mv][1];
		
		if(in(a,b) && dis[a][b]!= inf){
			
			if(d==1+dis[a][b]) q.push({a,b,d-1,mv});
			else if(d==1001+dis[a][b]){
				q.push({a,b,d-1,mv});
				q.push({a,b,d-1001,(mv+1)%4});
				q.push({a,b,d-1001,(mv+3)%4});
			}
		}

	}
	return ans;
}

int main(){
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	int m=arr[0].size(),x=n-2,y=1;
	vector<vector<int>> dis(n,vector<int>(n,inf));
	int ans=dijkstra(arr,x,y,0,dis);

	cout<<"Part 1: "<<ans<<"\n";

	int cnt=bfs(dis,ans);

	cout<<"Part 2: "<<cnt<<"\n";
	
	return 0;
}
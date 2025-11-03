
#include <bits/stdc++.h>
using namespace std;

#define n 141
#define inf (1e9)
#define piv pair<int,vector<int>>

bool in(int x,int y){
	return x>0 && y>0 && x<n && y<n;
}

int dijkstra(vector<string> &arr,int i,int j,int dir){

	priority_queue<piv,vector<piv>,greater<piv>> pq;
	vector<vector<int>> dis(n,vector<int>(n,inf));
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

int main(){
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	int m=arr[0].size(),x=n-2,y=1;
	
	int ans=dijkstra(arr,x,y,0);

	cout<<ans<<"\n";

	return 0;
}

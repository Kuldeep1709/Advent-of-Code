#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=130,x,y;
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	for(int i=0;i<n;i++){
		bool found=false;
		for(int j=0;j<n;j++){
			if(arr[i][j]== '^'){
				found=true;
				x=i,y=j;
			}
		}
		if(found) break;
	}

	vector<vector<int>> move = {{-1,0}, {0,1}, {1,0}, {0,-1}}; 
	vector<vector<bool>> visited(n,vector<bool>(n,false));
	visited[x][y]=true;
	arr[x][y]='.';
	int mv=0,ans=1;
	int nx=x+move[mv][0],ny=y+move[mv][1];
	while(nx<n && ny<n && nx>=0 && ny>=0){
		if(arr[nx][ny]=='.'){
			x=nx,y=ny;
			if(!visited[nx][ny]) visited[nx][ny]=true,ans++;
		}
		else mv=(mv+1)%4;
		nx=x+move[mv][0];
		ny=y+move[mv][1];
	}

	cout<<ans<<"\n";

	return 0;
}

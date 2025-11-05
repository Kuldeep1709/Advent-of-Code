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
	int a=x,b=y;
	arr[x][y]='.';
	
	int ans=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='.'){
				arr[i][j]='#';

				x=a,y=b;
				int mv=0,steps=0;
				int nx=x+move[mv][0],ny=y+move[mv][1];
				
				while(nx<n && ny<n && nx>=0 && ny>=0 && steps<=(n*n)){
					if(arr[nx][ny]=='.') x=nx,y=ny;
					else mv=(mv+1)%4;

					nx=x+move[mv][0];
					ny=y+move[mv][1];
					steps++;
				}

				if(steps>(n*n)) ans++;
				arr[i][j]='.';
			}
		}
	}

	cout<<ans<<"\n";

	return 0;
}

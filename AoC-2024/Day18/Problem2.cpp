#include <bits/stdc++.h>
using namespace std;

#define n 71
#define m 3450

bool in(int x,int y){
	return x>=0 && y>=0 && x<n && y<n;
}

int bfs(vector<string> arr){
	queue<vector<int>> q;
	q.push({0,0,0});
	arr[0][0]='#';
	vector<vector<int>> move={{1,0},{-1,0},{0,1},{0,-1}};

	while(!q.empty()){
		vector<int> a=q.front();
		q.pop();

		int x=a[0],y=a[1],ans=a[2];
		if(x==n-1 && y==n-1) return ans;

		for(vector<int> ele:move){
			int dx=ele[0],dy=ele[1];
			if(in(x+dx,y+dy) && arr[x+dx][y+dy]=='.'){
				q.push({x+dx,y+dy,ans+1});
				arr[x+dx][y+dy]='#';
			}
		}
	}
	return -1; // No Path
}

int main(){
	vector<vector<int>> arr(m,vector<int>(2));
	vector<string> grid(n,string(n,'.'));

	for(int i=0;i<m;i++){
		string s,t;cin>>s;
		int j=0;
		while(s[j]!=',') t.push_back(s[j]),j++;

		int a=stoi(t);
		int b=stoi(s.substr(j+1));
		arr[i][0]=a;
		arr[i][1]=b;
	}
	for(int i=0;i<1024;i++){
		int a=arr[i][0],b=arr[i][1];
		grid[a][b]='#';
	}

	int l=1024,r=m-1; // l=1024 as wkt soln for 1023(0-indexed) Exists
	int x,y;

	while(l<=r){
		int mid=l+(r-l)/2;
		
		int a,b;
		for(int i=l;i<=mid;i++){
			a=arr[i][0];
			b=arr[i][1];
			grid[a][b]='#';
		}

		int temp=bfs(grid);

		if(temp==-1){
			x=a;
			y=b;
			r=mid-1;
			for(int i=l;i<=mid;i++){
				a=arr[i][0];
				b=arr[i][1];
				grid[a][b]='.';
			}
		}
		else l=mid+1;
	}

	cout<<x<<","<<y<<"\n";

	return 0;
}
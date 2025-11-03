#include<bits/stdc++.h>
using namespace std;

bool in(int x,int y,int n){
	return (x>=0 && y>=0 && x<n && y<n);
}

int main(){
	int n=50,ans=0;
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	unordered_map<char,vector<vector<int>>> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]!='.'){
				m[arr[i][j]].push_back({i,j});
			}
		}
	}
	vector<vector<bool>> vis(n,vector<bool> (n,false));
	for(auto ele:m){
		vector<vector<int>> vec=ele.second;
		int p=vec.size();
		for(int i=0;i<p;i++){
			for(int j=i+1;j<p;j++){
				int a=vec[i][0],b=vec[i][1],c=vec[j][0],d=vec[j][1];
				int h=c-a,k=d-b;
				if(in(c+h,d+k,n) && !vis[c+h][d+k]) ans++,vis[c+h][d+k]=true;
				if(in(a-h,b-k,n) && !vis[a-h][b-k]) ans++,vis[a-h][b-k]=true;
			}
		}
	}
	cout<<ans<<"\n";

	return 0;
}

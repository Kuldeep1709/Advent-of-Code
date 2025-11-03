#include<bits/stdc++.h>
using namespace std;

bool in_map(int x,int y,int n=40){
	return x>=0 && y>=0 && x<n && y<n;
}

void dfs(int i,int j,char val,vector<string> &map,long long &ans){
	if(val=='9'){
		if(in_map(i+1,j) && map[i+1][j]==val) ans++;
		if(in_map(i,j+1) && map[i][j+1]==val) ans++;
		if(in_map(i-1,j) && map[i-1][j]==val) ans++;
		if(in_map(i,j-1) && map[i][j-1]==val) ans++;
	}
	else{
		if(in_map(i+1,j) && map[i+1][j]==val) dfs(i+1,j,char(val+1),map,ans);
		if(in_map(i,j+1) && map[i][j+1]==val) dfs(i,j+1,char(val+1),map,ans);
		if(in_map(i-1,j) && map[i-1][j]==val) dfs(i-1,j,char(val+1),map,ans);
		if(in_map(i,j-1) && map[i][j-1]==val) dfs(i,j-1,char(val+1),map,ans);
	}
	return;
}

int main(){
	long long ans=0;
	int n=40;
	vector<string> map(n);
	for(int i=0;i<n;i++) cin>>map[i];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='0'){
				dfs(i,j,'1',map,ans);
			}
		}
	}

	cout<<ans<<"\n";

	return 0;
}

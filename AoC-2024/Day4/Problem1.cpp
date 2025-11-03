#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=140,ans=0;
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='X'){
				if(i+3<n && arr[i+1][j]=='M' && arr[i+2][j]=='A' && arr[i+3][j]=='S') ans++;
				if(j+3<n && arr[i][j+1]=='M' && arr[i][j+2]=='A' && arr[i][j+3]=='S') ans++;
				if(i-3>=0 && arr[i-1][j]=='M' && arr[i-2][j]=='A' && arr[i-3][j]=='S') ans++;
				if(j-3>=0 && arr[i][j-1]=='M' && arr[i][j-2]=='A' && arr[i][j-3]=='S') ans++;
				if(i-3>=0 && j-3>=0 && arr[i-1][j-1]=='M' && arr[i-2][j-2]=='A' && arr[i-3][j-3]=='S') ans++;
				if(i-3>=0 && j+3<n && arr[i-1][j+1]=='M' && arr[i-2][j+2]=='A' && arr[i-3][j+3]=='S') ans++;
				if(i+3<n && j+3<n && arr[i+1][j+1]=='M' && arr[i+2][j+2]=='A' && arr[i+3][j+3]=='S') ans++;
				if(i+3<n && j-3>=0 && arr[i+1][j-1]=='M' && arr[i+2][j-2]=='A' && arr[i+3][j-3]=='S') ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
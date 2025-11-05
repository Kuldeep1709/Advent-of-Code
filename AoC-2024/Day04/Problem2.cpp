#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=140,ans=0;
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='A'){
				if(i-1>=0 && j-1>=0 && i+1<n && j+1<n){
					if(arr[i-1][j-1]==arr[i+1][j-1] && arr[i-1][j+1]==arr[i+1][j+1] && arr[i-1][j-1]=='M' && arr[i+1][j+1]=='S') ans++;
					else if(arr[i-1][j-1]==arr[i+1][j-1] && arr[i-1][j+1]==arr[i+1][j+1] && arr[i-1][j-1]=='S' && arr[i+1][j+1]=='M') ans++;
					else if(arr[i-1][j-1]==arr[i-1][j+1] && arr[i+1][j-1]==arr[i+1][j+1] && arr[i-1][j-1]=='M' && arr[i+1][j+1]=='S') ans++;
					else if(arr[i-1][j-1]==arr[i-1][j+1] && arr[i+1][j-1]==arr[i+1][j+1] && arr[i-1][j-1]=='S' && arr[i+1][j+1]=='M') ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
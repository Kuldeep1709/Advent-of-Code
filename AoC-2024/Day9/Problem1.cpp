#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	vector<int> arr;
	int id=0,n=s.size();

	for(int i=0;i<n;i++){
		if(!(i&1)){
			for(int j=0;j<(s[i]-'0');j++) arr.push_back(id);
			id++;
		}
		else for(int j=0;j<(s[i]-'0');j++) arr.push_back(-1);
	}

	int i=0,j=arr.size()-1;
	while(i<j){
		if(arr[i]!=-1) i++;
		else if(arr[j]==-1) j--;
		else{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	
	unsigned long long ans=0;
	int idx=1,p=arr.size();

	while(idx<p && arr[idx]!=-1) ans+=(idx*(arr[idx])),idx++;

	cout<<ans<<"\n";

	return 0;
}

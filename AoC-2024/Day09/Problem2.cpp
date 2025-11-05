#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	vector<int> arr;
	int id=0,n=s.size();
	vector<pair<int,int>> neg;
	vector<pair<int,int>> pos;
	for(int i=0;i<n;i++){
		if(!(i&1)){
			pos.push_back({arr.size(),s[i]-'0'});
			for(int j=0;j<(s[i]-'0');j++) arr.push_back(id);
			id++;
		}
		else{
			neg.push_back({arr.size(),s[i]-'0'});
			for(int j=0;j<(s[i]-'0');j++) arr.push_back(-1);
		}
	}


	int a=pos.size(),b=neg.size(),p=arr.size();
	for(int i=a-1;i>=0;i--){
		for(int j=0;j<b;j++){
			if(neg[j].second>=pos[i].second && neg[j].first<pos[i].first){

				int len=pos[i].second,x=pos[i].first,y=neg[j].first,val=arr[x];

				for(int k=0;k<len;k++) arr[y+k]=val,arr[x+k]=-1;
				neg[j].first+=len;
				neg[j].second-=len;
				break;

			}
		}
	}

	unsigned long long ans=0;
	int idx=1;

	while(idx<p){
		if(arr[idx]!=-1) ans+=(idx*(arr[idx]));
		idx++;
	}

	cout<<ans<<"\n";

	return 0;
}

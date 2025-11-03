#include<bits/stdc++.h>
using namespace std;

int main(){
	long long ans=0;
	unordered_map<int,vector<int>> m;
	for(int i=0;i<1176;i++){
		string s;cin>>s;
		int a=((s[0]-'0')*10)+(s[1]-'0');
		int b=((s[3]-'0')*10)+(s[4]-'0');
		m[a].push_back(b);
	}
	for(int j=0;j<202;j++){
		string s;cin>>s;
		int n=s.size();
		unordered_map<int,bool> printed;
		bool curr=true;

		for(int i=0;i<n-1;i+=3){
			int num=((s[i]-'0')*10)+(s[i+1]-'0');

			bool next=false;
			for(int x:m[num]){
				if(printed.count(x)){
					next=true;
					break;
				}
			} 
			if(next){
				curr=false;
				break;
			}
			printed[num]=true;
		}

		if(curr){
			int mid=n/2;
			int num=((s[mid-1]-'0')*10)+(s[mid]-'0');
			ans+=num;
		}
	}

	cout<<ans<<"\n";

	return 0;
}

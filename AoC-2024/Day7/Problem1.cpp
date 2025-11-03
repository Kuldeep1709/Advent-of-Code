#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

bool Possible(ull target,vector<ull> &arr,int idx,ull result){
	if(result==target && idx==arr.size()) return true;
	if(result>target || idx==arr.size()) return false;
	if(Possible(target,arr,idx+1,result+arr[idx])) return true;
	return Possible(target,arr,idx+1,result*arr[idx]);
}

int main(){
	ull ans=0;
	for(int j=0;j<850;j++){
		string s;getline(cin,s);
		ull target=0,i=0,n=s.size();
		while(s[i]!=':') target=(target*10)+(s[i++]-'0');
		i+=2;
		vector<ull> arr;
		while(i<n){
			ull a=0;
			while(i<n && s[i]!=' ') a=(a*10)+s[i++]-'0';
			i++;
			arr.push_back(a);
		}
		if(Possible(target,arr,1,arr[0]))  ans+=target;
	}
	cout<<ans<<"\n";
}

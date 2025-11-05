#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=1000;
	vector<int> arr(n);
	unordered_map<int,int> m;

	for(int i=0;i<n;i++){
		cin>>arr[i];
		int a;cin>>a;
		m[a]++;
	}
	long long ans=0;
	for(int i=0;i<n;i++) ans+=(arr[i]*(m[arr[i]]));
	cout<<ans<<"\n";
	return 0;
}
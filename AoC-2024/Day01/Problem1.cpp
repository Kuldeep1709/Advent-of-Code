#include<bits/stdc++.h>
using namespace std;

int main(){
	int n=1000;
	vector<int> arr(n);
	vector<int> a(n),b(n);

	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	long long ans=0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++) ans+=(abs(a[i]-b[i]));
	cout<<ans<<"\n";
	return 0;
}
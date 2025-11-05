#include<bits/stdc++.h>
using namespace std;

int main(){
	long long ans=0;
	for(int i=0;i<6;i++){
		string s;
		getline(cin,s);
		int n=s.size();
		for(int i=0;i<n-4;i++){
			if(s.substr(i,4)=="mul("){
				string a,b;
				i+=4;
				while(i<n && s[i]<='9' && s[i]>='0') a.push_back(s[i++]);
				if(i<n && s[i]==',') i++;
				else continue;
				while(i<n && s[i]<='9' && s[i]>='0') b.push_back(s[i++]);
				if(i<n && s[i]==')' && a.size() && b.size()) ans+=(stoi(a,0,10)*stoi(b,0,10));
			}
		}
	}
	
	cout<<ans<<"\n";

	return 0;
}

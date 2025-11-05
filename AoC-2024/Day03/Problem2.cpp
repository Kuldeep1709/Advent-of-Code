#include<bits/stdc++.h>
using namespace std;

int main(){
	long long ans=0;
	bool pass=true;
	for(int i=0;i<6;i++){
		string s;
		getline(cin,s);
		int n=s.size();
		for(int i=0;i<n-7;i++){
			if(pass && s.substr(i,4)=="mul("){
				string a,b;
				i+=4;
				while(i<n && s[i]<='9' && s[i]>='0') a.push_back(s[i++]);
				if(i<n && s[i]==',') i++;
				else continue;
				while(i<n && s[i]<='9' && s[i]>='0') b.push_back(s[i++]);
				if(i<n && s[i]==')' && a.size() && b.size()) ans+=(stoi(a,0,10)*stoi(b,0,10));
			}
			else if(s.substr(i,7)=="don't()"){
				pass=false;
				i+=7;
				while(i<n-4 && s.substr(i,4)!="do()") i++;
				if(s.substr(i,4)=="do()") pass=true;
			}
		}
	}

	cout<<ans<<"\n";

	return 0;
}
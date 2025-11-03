#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long combo(long long A,long long B,long long C,long long b){
	if(b<=3) return b;
    else if(b==4) return A;
    else if(b==5) return B;
    return C;
}

long long rev_eng(vector<int> target,long long ans,long long idx){
	if(idx<0) return ans;

	for(long long i=0;i<8;i++){
		long long A= ((ans<<3)|i);
		long long B=0,C=0,res=-1;

		for(int ip=0;ip<target.size()-2;ip+=2){

			long long a=target[ip],b=target[ip+1],c=combo(A,B,C,b);
			
		    if(a == 1) B = B ^ b;
		    else if(a == 2) B=c%8;
		    
		    else if(a == 4) B = B ^ C;
		    else if(a == 5) res=c%8;
		    else if(a == 6) B=(A>>c);
		    else if(a == 7) C=(A>>c);

		    if(res==target[idx]){
		    	long long nxt=rev_eng(target,A,idx-1);
		    	if(nxt!=-1) return nxt;
		    	else continue;
		    }
		}
	}
	return -1; // Temporary Output
}


int main(){
	string p,q,r,s;
	getline(cin,p);
	getline(cin,q);
	getline(cin,r);
	cin.ignore();
	getline(cin,s);

	vector<int> target;
	for(int i=9;i<s.size();i+=2) target.push_back(s[i]-'0');
	
	long long ans=rev_eng(target,0,target.size()-1);

	cout<<ans<<"\n";

	return 0;
}

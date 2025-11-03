#include <bits/stdc++.h>
using namespace std;

int A,B,C;

int combo(int b){
	if(b<=3) return b;
    else if(b==4) return A;
    else if(b==5) return B;
    return C;
}

int main(){
	string p,q,r,s;
	getline(cin,p);
	getline(cin,q);
	getline(cin,r);
	cin.ignore();
	getline(cin,s);

	A=stoi(p.substr(12));
	B=stoi(q.substr(12));
	C=stoi(r.substr(12));

	vector<int> opr;
	for(int i=9;i<s.size();i+=2) opr.push_back(s[i]-'0');

	int ip=0,n=opr.size();

	vector<int> ans;

	while(ip < n) {
	    int a=opr[ip],b=opr[ip + 1],c=combo(b);;

	    if(a == 0) A>>=c;
	    else if(a == 1) B^=b;
	    else if(a == 2) B=c%8;

	    else if(a == 3) {
	        if(A != 0) {
	            ip = b;
	            continue;
	        }
	    }

	    else if(a == 4) B^=C;

	    else if(a == 5) ans.push_back(c%8);
	    else if(a == 6) B=(A>>c);
	    else if(a == 7) C=(A>>c);
	    
	    ip += 2;
	}
	
	for(int i=0;i<ans.size()-1;i++) cout<<ans[i]<<",";
	cout<<ans[ans.size()-1]<<"\n";

	return 0;
}

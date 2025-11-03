#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define n 500


int main() {
    ull Q1=0,Q2=0,Q3=0,Q4=0;

    for(int i=0;i<n;i++){

    	string s;getline(cin,s);
    	for (char& c : s) if (c == '=' || c == 'p' || c == 'v') c = ' ';
	    stringstream ss(s);
	    char comma;
	    int x,y,vx,vy;
	    ss >> x >> comma >> y >> vx >> comma >> vy;

	    int fx=(((x+(vx * 100)%101)+101)%101);
	    int fy=(((y+(vy * 100)%103)+103)%103);

	    if(fx<50){
	    	if(fy<51) Q1++;
	    	else if(fy>51) Q3++;
	    }
		else if(fx>50){
			if(fy<51) Q2++;
			else if(fy>51) Q4++;
		}
    }
    cout<<(Q1*Q2*Q3*Q4)<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define n 320


int main() {

    ull ans=0;

    for (int i=0;i<n;i++){
    	string a,b,p;
    	getline(cin,a);
    	getline(cin,b);
    	getline(cin,p);
    	cin.ignore();
    	int x=0,y=0,targetx=0,targety=0;
    	
    	int x1=0;
    	int j=12;
    	while(a[j]!=',') x1=(x1*10)+(a[j]-'0'),j++;
    	x+=x1;
    	

    	int y1=0;
    	j+=4;
    	while(j<a.size()) y1=(y1*10)+(a[j]-'0'),j++;
    	x+=y1;
    	

    	int x2=0;
    	j=12;
    	while(b[j]!=',') x2=(x2*10)+(b[j]-'0'),j++;
    	y+=x2;
    	

    	int y2=0;
    	j+=4;
    	while(j<b.size()) y2=(y2*10)+(b[j]-'0'),j++;
    	y+=y2;
    	


    	j=9;

    	while(p[j]!=',') targetx=(targetx*10)+(p[j]-'0'),j++;
    	

    	j+=4;
    	while(j<p.size()) targety=(targety*10)+(p[j]-'0'),j++;
    	

    	int target=targetx+targety;

    	ull cost=(404);

    	int A=100,B=100;

    	for(int k=0;k<=A;k++){
    		for(int g=0;g<=B;g++){
    			if((k*x1 + g*x2)==targetx && (k*y1 + g*y2)==targety && (k*x)+(g*y)==target && cost>((3*k)+g)) cost=(3*k)+g;
    		}
    	}
    	if(cost < (404)) ans+=cost;

    	
    }
    

    cout << ans << "\n";

    return 0;
}
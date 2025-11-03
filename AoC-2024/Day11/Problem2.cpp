#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

unordered_map<string, ull> memo;

int num_digit(ull num){
	if(!num) return 1;
	int ans=0;
	while(num) ans++,num/=10;
	return ans;
}

ull stones(ull a, int blink){
    string key = to_string(a) + "_" + to_string(blink);

    if(memo.find(key) != memo.end()){
        return memo[key];
    }

	ull ans=1;
	if(blink){
		int d=num_digit(a);
		if(a==0) (ans=stones(1,blink-1));
		else if(!(num_digit(a)&1)){
			int idx=0;
			ull new_stone=0;
			while(idx<d/2){
				new_stone+=(a%10)*(pow(10,idx));
				idx++;
				a/=10;
			}
			ans+=(stones(a,blink-1));
			ans+=(stones(new_stone,blink-1));
			ans--;
		}
		else ans=(stones(a*2024,blink-1));
	}

    memo[key] = ans;

	return ans;
}

int main(){
	int n=8,blink=75;
	ull ans=0;
	for(int i=0;i<n;i++){
		ull a; cin >> a;
		ans += stones(a, blink);
	}

	cout << ans << "\n";

	return 0;
}

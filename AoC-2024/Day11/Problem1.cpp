#include<bits/stdc++.h>
using namespace std;

int num_digit(long long num){
	if(!num) return 1;
	int ans=0;
	while(num) ans++,num/=10;
	return ans;
}

int main(){
	int ans=8;
	vector<long long> arr(ans);
	for(int i=0;i<ans;i++) cin>>arr[i];
	for(int i=0;i<25;i++){
		int n=arr.size();
		for(int i=0;i<n;i++){
			int d=num_digit(arr[i]);
			if(arr[i]==0) arr[i]++;
			else if(!(num_digit(arr[i])&1)){
				int idx=0;
				long long new_stone=0;
				while(idx<d/2){
					new_stone+=(arr[i]%10)*(pow(10,idx));
					idx++;
					arr[i]/=10;
				}
				arr.push_back(new_stone);
			}
			else arr[i]*=2024;
		}
	}
	cout<<arr.size()<<"\n";
	return 0;
}

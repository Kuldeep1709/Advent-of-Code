#include <bits/stdc++.h>
using namespace std;

long long prune(long long l) {
    return l % 16777216LL;
}

long long pseudo(long long s) {
    long long val = s * 64;
    s = s ^ val;
    s = prune(s);
  
    val = s / 32;
    s = s ^ val;
    s = prune(s);
  
    val = s * 2048;
    s = s ^ val;
    s = prune(s);

    return s;
}


int main() {
    int n=1515;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    
    long long ans=0;
    
    for(long long s:arr){
        long long a=s;
        for(int i=0;i<2000;i++) a=pseudo(a);
        ans+=a;
    }
    
    cout<<ans<<"\n";

    return 0;
}

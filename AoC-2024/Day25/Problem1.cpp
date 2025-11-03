#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> lock;
    vector<string> key;

    for(int i=0;i<500;i++){
        string ele="00000";
        string s;cin>>s;
        char c=s[0];
        for(int j=0;j<6;j++){   
            cin>>s;
            for(int k=0;k<5;k++) if(s[k]==c) ele[k]=char(ele[k]+1);
        }
        if(c=='.') key.push_back(ele);
        else lock.push_back(ele);
    }

    int ans=0;

    for(string l:lock){
        for(string k:key){
            bool ok=true;
            for(int i=0;i<5;i++) if(l[i]>k[i]) ok=false;
            if(ok) ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=3380;

    unordered_map<string,vector<string>> m;
    vector<string> arr;

    for(int i=0;i<n;i++){
        string s;cin>>s;
        string a=s.substr(0,2),b=s.substr(3);
        if(!m.count(a)) arr.push_back(a);
        if(!m.count(b)) arr.push_back(b);

        m[a].push_back(b);
        m[b].push_back(a);
    }

    int p=arr.size(),ans=0;

    for(int i=0;i<p;i++){
        for(int j=i+1;j<p;j++){
            for(int k=j+1;k<p;k++){
                bool a=false,b=false;
                for(string x:m[arr[i]]){
                    if(x==arr[j]) a=true;
                    if(x==arr[k]) b=true;
                }
                bool c=false,d=false;
                for(string y:m[arr[j]]){
                    if(y==arr[i]) c=true;
                    if(y==arr[k]) d=true;
                }
                bool e=false,f=false;
                for(string z:m[arr[k]]){
                    if(z==arr[j]) e=true;
                    if(z==arr[i]) f=true;
                }
                char x=arr[i][0],y=arr[j][0],z=arr[k][0];
                bool g=(x=='t' || y=='t' || z=='t');
                if(a && b && c && d && e && f && g) ans++;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}

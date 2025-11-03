#include <bits/stdc++.h>
using namespace std;

// Here "Bin_Dec" function takes reversed string representation of number as parameter

unsigned long long Bin_Dec(string s){
    unsigned long long ans=0;
    int n=s.size();
    for(int i=0;i<n;i++) ans+=((s[i]-'0')*(1ULL<<(i)));
    return ans;
}


int main() {
    int n=90,p=222;
    map<string,int> m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int val;cin>>val;
        s.pop_back();
        m[s]=val;
    }

    vector<vector<string>> arr(p);

    int total=0;
    int cnt=0;

    for(int i=0;i<p;i++){
        string a,b,c,d,e;cin>>a>>b>>c>>d>>e;
        if(e[0]=='z') total++;
        if(m.count(a) && m.count(c) && !m.count(e)){
            if(e[0]=='z') cnt++;
            if(b=="OR") m[e]=(m[a]|m[c]);
            else if(b=="AND") m[e]=(m[a]&m[c]);
            else m[e]=(m[a]^m[c]);
        }
        arr[i]={a,b,c,e};
    }

    while(cnt<total){
        for(int i=0;i<p;i++){
            string a=arr[i][0],b=arr[i][1],c=arr[i][2],e=arr[i][3];
            if(m.count(a) && m.count(c) && !m.count(e)){
                if(e[0]=='z') cnt++;
                if(b=="OR") m[e]=(m[a]|m[c]);
                else if(b=="AND") m[e]=(m[a]&m[c]);
                else m[e]=(m[a]^m[c]);
            }
        }
    }
    
    auto it=m.begin();
    string bin;
    while(it!=m.end()){
        if(it->first[0]=='z') bin.push_back(it->second+'0');
        it++;
    }

    unsigned long long ans=Bin_Dec(bin);

    cout<<ans<<"\n";

    return 0;
}

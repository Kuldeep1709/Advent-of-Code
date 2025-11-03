#include <bits/stdc++.h>
using namespace std;

#define uset unordered_set
#define umap unordered_map

// Bron-Kerbosch Algorithm
void BKA(uset<string> R, uset<string> P, uset<string> X, umap<string, uset<string>> &N, vector<uset<string>> &cliques) {
    if (P.empty() && X.empty()) {
        cliques.push_back(R);
        return;
    }
    auto it=P.begin();
    while(it != P.end()){
        string v = *it;

        uset<string> p; // Neighbours of P
        for (string neigh : N[v]) {
            if (P.count(neigh)) {
                p.insert(neigh);
            }
        }

        uset<string> x; // Neighbours of X
        for (string neigh : N[v]) {
            if (X.count(neigh)) {
                x.insert(neigh);
            }
        }

        R.insert(v);
        BKA(R, p, x, N, cliques);

        R.erase(v);
        it = P.erase(it);
        X.insert(v);
    }
}

int main() {
    int n=3380;

    umap<string, uset<string>> N;

    for(int i=0;i<n;i++){
        string s;cin>>s;
        string a=s.substr(0,2),b=s.substr(3);

        N[a].insert(b);
        N[b].insert(a);
    }
    
    uset<string> R, P, X;
    for (auto ele:N) P.insert(ele.first);

    vector<uset<string>> cliques;

    BKA(R, P, X, N, cliques);

    uset<string> temp;
    int maxi=0;
    for (auto sub : cliques) {
        if(sub.size()>maxi){
            temp=sub;
            maxi=sub.size();
        }
    }

    vector<string> arr;
    for(auto v:temp) arr.push_back(v);
    sort(arr.begin(),arr.end());
    
    string ans;

    for(string s:arr) ans+=s+",";
    ans.pop_back();
    cout<<ans<<"\n";

    return 0;
}

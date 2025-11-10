#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> getNums(const string& s) {
    vector<ll> v;
    stringstream ss(s);
    ll x;
    while (ss >> x) v.push_back(x);
    return v;
}

void solve() {
    int idx = 0;
    string line;
    vector<vector<ll>> report;

    while(getline(cin,line)) report.push_back(getNums(line));

    ll ans = 0;

    for(const auto &line: report){
        ll curr = 0;
        bool allZero = false;
        vector<ll> diffArr = line;

        while(not allZero){
            bool allSame = true;
            const int n = diffArr.size();
            curr += diffArr[n-1];

            for(int i=1;i<n;i++){
                if(diffArr[i] != diffArr[i-1]) allSame = false;
                diffArr[i-1] = diffArr[i] - diffArr[i-1];
            }
            diffArr.pop_back();
            if(allSame) allZero = true;
        }
        ans += curr;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
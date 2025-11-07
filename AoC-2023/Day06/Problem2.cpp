#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll merge(const string &s){
    ll ans = 0;
    for(const char &c: s){
        if(c >= '0' && c <= '9'){
            ans = 10*ans + (c-'0');
        }
    }
    return ans;
}

ll ways(const ll &time, const ll &dist){
    for(ll t=1;t < time; t++){
        if((time-t)*t > dist){
            return time - 2*t + 1;
        }
    }
    return 0;
}

void solve() {    
    string time,dist;
    getline(cin, time);
    getline(cin, dist);

    ll oneTime = merge(time);
    ll oneDist = merge(dist);

    ll ans = ways(oneTime, oneDist);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
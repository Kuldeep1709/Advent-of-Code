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

    vector<ll> timeList = getNums(time.substr(time.find(":") + 1));
    vector<ll> distList = getNums(dist.substr(dist.find(":") + 1));

    ll ans = 1, n = timeList.size();

    for(int i=n-1;i>=0;i--) ans*= ways(timeList[i], distList[i]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> seeds;

vector<ll> getNums(const string& s) {
    vector<ll> v;
    stringstream ss(s);
    ll x;
    while (ss >> x) v.push_back(x);
    return v;
}

ll dfs(ll idx, ll seed, vector<vector<array<ll,3>>> maps){
    if(idx+1 == maps.size()){
        for(auto triplet: maps[idx]){
            ll dest = triplet[0], src = triplet[1], cnt = triplet[2];

            if(src <= seed && seed < src + cnt) return dest + (seed-src);
        }
        return seed;
    }

    for(auto triplet: maps[idx]){
        ll dest = triplet[0], src = triplet[1], cnt = triplet[2];

        if(src <= seed && seed < src + cnt){
            return dfs(idx+1, dest + (seed-src), maps);
        }
    }

    return dfs(idx+1, seed, maps);
}

void solve() {    
    string line;
    getline(cin,line);
    seeds = getNums(line.substr(line.find(":") + 1));

    getline(cin,line); // skip line

    vector<vector<array<ll,3>>> maps;

    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        vector<array<ll,3>> block;

        while (getline(cin, line)) {
            if (line.empty()) break;
            auto nums = getNums(line);
            block.push_back({nums[0], nums[1], nums[2]});
        }
        maps.push_back(block);
    }

    ll ans = INT_MAX;

    for(const ll seed: seeds) ans = min(ans, dfs(0, seed, maps));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
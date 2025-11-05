#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> seeds;
map<pair<ll,ll>, ll> memo;

vector<ll> getNums(const string& s) {
    vector<ll> v;
    stringstream ss(s);
    ll x;
    while (ss >> x) v.push_back(x);
    return v;
}

// BruteForce DFS : Time Limit Exceeded
ll dfs(ll idx, ll seed, vector<vector<array<ll,3>>> maps){
    if(idx+1 == maps.size()){
        for(auto triplet: maps[idx]){
            ll dest = triplet[0], src = triplet[1], cnt = triplet[2];

            if(src <= seed && seed < src + cnt){
                return memo[{idx, seed}] = dest + (seed-src);
            }
        }
        return seed;
    }

    if(memo.count({idx, seed})) return memo[{idx, seed}];

    for(auto triplet: maps[idx]){
        ll dest = triplet[0], src = triplet[1], cnt = triplet[2];

        if(src <= seed && seed < src + cnt){
            return memo[{idx, seed}] = dfs(idx+1, dest + (seed-src), maps);
        }
    }

    return memo[{idx, seed}] = dfs(idx+1, seed, maps);
}

// Modified DFS : considering overlaps
ll dfsModified(int idx, ll left, ll right, vector<vector<array<ll,3>>> &maps){
    if(idx == maps.size()) return left;

    ll ans = LLONG_MAX;

    bool noOverlap = true;

    for(auto triplet: maps[idx]){
        ll dest = triplet[0], src = triplet[1], len = triplet[2];

        ll overlapStart = max(left, src);
        ll overlapEnd = min(right, src + len);

        if(overlapStart < overlapEnd){
            noOverlap = false;
            ll nextLeft = dest + overlapStart - src;
            ll nextRight = dest + overlapEnd - src;

            ans = min(ans, dfsModified(idx+1, nextLeft, nextRight, maps));

            if(overlapStart > left) ans = min(ans, dfsModified(idx, left, overlapStart-1, maps));
            if(overlapEnd < right) ans = min(ans, dfsModified(idx, overlapEnd+1, right, maps));
        }
    }

    if(noOverlap) ans = min(ans, dfsModified(idx+1, left, right, maps));

    return ans;
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

    ll ans = INT_MAX, n = seeds.size();

    for(int i=0;i<n;i+=2){
        ans = min(ans, dfsModified(0, seeds[i], seeds[i]+seeds[i+1], maps));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
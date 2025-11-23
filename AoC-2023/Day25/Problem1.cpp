#include <bits/stdc++.h>
using namespace std;

struct Result {
    int cut;
    int size1;
    int size2;
};

Result kargerOnce(unordered_map<string, vector<string>> g) {
    unordered_map<string, int> compSize;
    for(auto &p: g) compSize[p.first] = 1;

    while(g.size() > 2){
        auto it = g.begin();
        advance(it, rand() % g.size()); // shift the iterator randomly
        string u = it->first;

        vector<string>& neigh = it->second;
        string v = neigh[rand() % neigh.size()];

        for(string x : g[v]){
            if(x != u) g[u].push_back(x);

            auto &list = g[x];
            for(string &y : list) {
                if(y == v) y = u;
            }
        }

        compSize[u] += compSize[v];
        compSize.erase(v);

        auto &arrU = g[u];
        arrU.erase(remove(arrU.begin(), arrU.end(), u), arrU.end());
        g.erase(v);
    }

    auto it = g.begin();
    auto it2 = it; ++it2;

    int cut = it->second.size();
    int s1 = compSize[it->first];
    int s2 = compSize[it2->first];

    return {cut, s1, s2};
}

Result kargerRandomized(unordered_map<string, vector<string>>& adj) {
    while(true){
        Result r = kargerOnce(adj);
        if (r.cut == 3) return r;
    }
}

void solve(){
    string line;
    unordered_map<string, vector<string>> adj;

    while (getline(cin, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string u, v; 
        ss >> u;
        u.pop_back();

        while (ss >> v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    srand(time(0));

    Result ans = kargerRandomized(adj);

    // cout << "MinCut = " << ans.cut << "\n";
    // cout << "Component sizes: " << ans.size1 << ", " << ans.size2 << "\n";

    cout << ans.size1 * ans.size2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

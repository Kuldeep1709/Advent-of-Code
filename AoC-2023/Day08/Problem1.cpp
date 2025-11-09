#include <bits/stdc++.h>
using namespace std;

void solve() {
    string instructs;cin>>instructs;
    cin.ignore();

    string node;
    unordered_map<string,pair<string,string>> network;

    while(getline(cin,node)){
        int idx = 0, n = node.size();

        string start;
        while(idx < n && node[idx] != ' ')  start.push_back(node[idx++]);

        while(idx < n && node[idx] != '(') idx++;
        idx++;

        string nodeL, nodeR;
        while(idx < n && node[idx] != ',')  nodeL.push_back(node[idx++]);
        idx+=2;
        while(idx < n && node[idx] != ')')  nodeR.push_back(node[idx++]);

        network[start] = {nodeL, nodeR};
    }

    bool reached = false;
    string curr = "AAA", dest = "ZZZ";
    long long idx = 0, N = instructs.size(), steps = 0;

    while(!reached){
        if(instructs[idx] == 'L') curr = network[curr].first;
        else curr = network[curr].second;

        if(curr == dest) reached = true;
        idx = (idx+1)%N;

        steps++;
    }

    cout << steps << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
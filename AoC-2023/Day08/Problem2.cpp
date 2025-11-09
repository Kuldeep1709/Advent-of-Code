#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

void solve() {
    string instructs;cin>>instructs;
    cin.ignore();

    string node;
    vector<string> startNodes;
    unordered_map<string,tuple<string,string,bool>> network;

    while(getline(cin,node)){
        int idx = 0, n = node.size();

        string start;
        bool containsZ = false;
        bool isStartNode = false;
        while(idx < n && node[idx] != ' '){
            if(node[idx] == 'Z') containsZ = true;
            else if(node[idx] == 'A') isStartNode = true;
            start.push_back(node[idx++]);
        }

        while(idx < n && node[idx] != '(') idx++;
        idx++;

        string nodeL, nodeR;
        while(idx < n && node[idx] != ',')  nodeL.push_back(node[idx++]);
        idx+=2;
        while(idx < n && node[idx] != ')')  nodeR.push_back(node[idx++]);

        network[start] = {nodeL, nodeR, containsZ};
        if(isStartNode) startNodes.push_back(start);
    }

    long long ans = 1;

    for(const string &startNode: startNodes){
        bool reached = false;
        string curr = startNode;
        long long steps = 0, idx = 0, N = instructs.size();

        while(!reached){
            if(instructs[idx] == 'L') curr = get<0>(network[curr]);
            else curr = get<1>(network[curr]);

            if(get<2>(network[curr])) reached = true;
            idx = (idx+1)%N;

            steps++;
        }

        ans = lcm(ans, steps);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
#include <bits/stdc++.h>
using namespace std;

int slot = 0;
vector<unordered_map<string,pair<int,int>>> boxes(256);

int HASH(const string &seq){
    int result = 0;
    for(const char &c: seq){
        result += (int)(c);
        result *= 17;
        result %= 256;
    }
    return result;
}

void printer(const string &curr){
    int opIdx = 0, n = curr.size();
    while(opIdx < n && curr[opIdx] != '=' && curr[opIdx] != '-') opIdx++;

    char op = curr[opIdx];
    string label = curr.substr(0,opIdx);
    int focalLength = 0;
    if(opIdx+1 < n && op == '=') focalLength = stoi(curr.substr(opIdx+1));

    int box = HASH(label);

    if(op == '='){
        if(boxes[box].count(label)) boxes[box][label].second = focalLength;
        else boxes[box][label] = {slot, focalLength};
    }
    else if(boxes[box].count(label)) boxes[box].erase(label);

    slot++;
}

void solve() {
    string line;cin>>line;

    string curr;

    for(const char &c: line){
        if(c == ','){
            printer(curr);
            curr = "";
        }
        else curr.push_back(c);
    }
    printer(curr);

    long long ans = 0;

    vector<vector<pair<int,int>>> final(256);
    for(int b=0;b<256;b++){
        for(auto &ele: boxes[b]){
            final[b].push_back(ele.second);
        }
    }

    for(auto &b: final) {sort(b.begin(), b.end());}

    for(int b=0;b<256;b++){
        const int n = final[b].size();
        for(int s=0;s<n;s++){
            ans += 1LL*(b+1)*(s+1)*(final[b][s].second);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
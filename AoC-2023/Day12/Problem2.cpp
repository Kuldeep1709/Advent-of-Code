#include <bits/stdc++.h>
using namespace std;

vector<int> getNums(const string& s) {
    vector<int> nums;
    string token;
    stringstream ss(s);

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            nums.push_back(stoi(token));
        }
    }

    return nums;
}

map<pair<int,int>, long long> memo;

long long arrangements(const string &spring, const vector<int> &groups, int groupIdx = 0, int springIdx = 0){
    if(groupIdx == groups.size()){
        bool valid = (spring.find('#', springIdx) == string::npos);
        if(valid) return 1LL;
        return 0LL;
    }

    if(springIdx == spring.size()) return 0LL;

    pair<int,int> key = {groupIdx, springIdx};

    if(memo.count(key)) return memo.at(key);

    long long count = 0;

    if(spring[springIdx] == '.' || spring[springIdx] == '?'){
        count += arrangements(spring, groups, groupIdx, springIdx+1);
    }
    if(spring[springIdx] == '#' || spring[springIdx] == '?'){
        int damaged = 0, req = groups[groupIdx], n = spring.size();
        while(damaged < req && springIdx + damaged < n && spring[springIdx + damaged] != '.'){
            damaged++;
        }

        if(damaged == req && (springIdx + damaged >= n || spring[springIdx + damaged] != '#')){
            count += arrangements(spring ,groups, groupIdx+1, springIdx+damaged+1);
        }
    }

    return memo[key] = count;
}

void solve() {
    string line;
    long long ans = 0;

    while(getline(cin, line)){
        int idx = 0, n = line.size();

        while(idx < n && line[idx] != ' ') idx++;

        string spring = line.substr(0, idx);
        const vector<int> groups = getNums(line.substr(idx+1));

        string updatedSpring;
        vector<int> updatedGroups;
        for(int i=0;i<5;i++){
            updatedSpring += (spring + "?");
            for(const int &g: groups) updatedGroups.push_back(g);
        }
        updatedSpring.pop_back();
        memo.clear();

        ans += arrangements(updatedSpring, updatedGroups);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
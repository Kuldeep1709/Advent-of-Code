#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int> &update, unordered_map<int, vector<int>> &rules) {
    unordered_map<int, bool> printed;
    for (int page : update) {
        for (int next : rules[page]) {
            if (printed.count(next)) {
                return false;
            }
        }
        printed[page] = true;
    }
    return true;
}

vector<int> reorder(vector<int> &update, unordered_map<int, vector<int>> &rules) {
    unordered_map<int, int> indegree;
    unordered_map<int, vector<int>> graph;
    set<int> pages(update.begin(), update.end());
    
    for (int page : pages) {
        for (int next : rules[page]) {
            if (pages.count(next)) {
                graph[page].push_back(next);
                indegree[next]++;
            }
        }
        if (!indegree.count(page)) indegree[page] = 0;
    }
    
    queue<int> q;
    for (auto ele : indegree) if(ele.second==0) q.push(ele.first);
    
    vector<int> correct;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        correct.push_back(curr);
        for (int next : graph[curr]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }
    
    return correct;
}

int main() {

    long long ans = 0;
    unordered_map<int, vector<int>> rules;

    for (int i = 0; i < 1176; i++) {
        string s; cin >> s;
        int a = ((s[0] - '0') * 10) + (s[1] - '0');
        int b = ((s[3] - '0') * 10) + (s[4] - '0');
        rules[a].push_back(b);
    }

    for (int j = 0; j < 202; j++) {
        string s; cin >> s;
        int n = s.size();
        vector<int> update;
        for (int i = 0; i < n; i += 3) {
            int num = ((s[i] - '0') * 10) + (s[i + 1] - '0');
            update.push_back(num);
        }

        if (!ok(update, rules)){
            vector<int> correct = reorder(update, rules);
            int mid = correct.size() / 2;
            ans += correct[mid];
        }
    }

    cout<<ans<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Note : This codes takes around 10-20 seconds

long long prune(long long l) {
    return l % 16777216LL;
}

long long pseudo(long long s) {
    long long val = s * 64;
    s = s ^ val;
    s = prune(s);
  
    val = s / 32;
    s = s ^ val;
    s = prune(s);
  
    val = s * 2048;
    s = s ^ val;
    s = prune(s);

    return s;
}

int main() {
    int n=1515;

    vector<long long> arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];

    map<vector<int>,long long> m;

    for (int i=0;i<n;i++) {
        long long num = arr[i];
        vector<int> change;
        change.push_back(num % 10);

        for (int j = 0; j < 2000; j++) {
            num = pseudo(num);
            change.push_back(num % 10);
        }

        set<vector<int>> vis;

        for (int k = 0; k < change.size() - 4; k++) {
            int a=change[k],b=change[k+1],c=change[k+2],d=change[k+3],e=change[k+4];
            vector<int> seq = {b - a, c - b, d - c, e - d};

            if (vis.find(seq) != vis.end()) continue;

            vis.insert(seq);

            if (m.find(seq) == m.end()) m[seq] = 0;

            m[seq] += e;
        }
    }

    long long ans = 0;
    for (auto x : m) ans = max(ans, x.second);

    cout << ans << "\n";

    return 0;
}

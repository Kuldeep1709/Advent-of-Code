#include <bits/stdc++.h>
using namespace std;

const int n = 400;

long long possible(const string &str, const unordered_map<string,bool> &strip) {
    int len = str.size();
    vector<long long> dp(len + 1, 0);
   	dp[0]=1;
    for (int i = 1; i <= len; i++) {
    	long long cnt=0;
        for (int j = 0; j < i; j++) {
            if (dp[j] && strip.count(str.substr(j, i - j))) cnt+=dp[j];
        }
        dp[i]=cnt;
    }
    return dp[len];
}

int main() {
    unordered_map<string,bool> strip;

    while (true) {
    	string s;cin >> s;
        if (s.back() == ',') {
            s.pop_back();
            strip[s]=true;
        } else {
            strip[s]=true;
            break;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ans+=possible(s,strip);
    }

    cout << ans << "\n";
    return 0;
}
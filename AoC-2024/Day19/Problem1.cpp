#include <bits/stdc++.h>
using namespace std;

const int n = 400;

bool possible(const string &str, const unordered_map<string,bool> &strip) {
    int len = str.size();
    vector<bool> dp(len + 1, false);
   	dp[0]=true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && strip.count(str.substr(j, i - j))){
            	dp[i]=true;
            	break;
            }
        }
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

   	int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;cin>>s;
        if(possible(s,strip)) ans++;
    }

    cout << ans << "\n";
    return 0;
}
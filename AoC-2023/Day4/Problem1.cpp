#include <bits/stdc++.h>
using namespace std;

const int N = 187;

void solve() {
    long long ans = 0;
    map<char,int> digits;
    for(int i=0;i<10;i++) digits[i+'0'] = i;

    for (int card=1;card<=N;card++) {
        string s;
        getline(cin, s);

        const int n = s.size();
        int idx = 0;
        while(s[idx] != ':') idx++;

        unordered_map<string, int> wins;

        while(s[idx] != '|'){
            if(digits.count(s[idx])){
                string val;
                while(digits.count(s[idx])) val.push_back(s[idx]), idx++;

                wins[val] = stoi(val);
            }
            idx++;
        }

        int bit = 0;

        while(idx < n){
            if(digits.count(s[idx])){
                string val;
                while(digits.count(s[idx])) val.push_back(s[idx]), idx++;

                if(wins.count(val)) bit++;
            }
            idx++;
        }

        if(bit > 0) ans += (1<<(bit-1));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
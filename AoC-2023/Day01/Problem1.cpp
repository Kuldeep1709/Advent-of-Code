#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

void solve() {
    long long ans = 0;
    map<char,int> digits;
    for(int i=0;i<10;i++) digits[i+'0'] = i;

    for (int line=1;line<=N;line++) {
        string s;
        getline(cin, s);

        int idx = 0, n = s.size();
        while(idx < n && !digits.count(s[idx])) idx++;

        if(idx < n) ans += 10*(digits[s[idx]]);

        idx = n-1;
        while(idx >= 0  && !digits.count(s[idx])) idx--;

        if(idx >= 0) ans += (digits[s[idx]]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

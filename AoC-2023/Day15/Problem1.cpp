#include <bits/stdc++.h>
using namespace std;

int HASH(const string &seq){
    int result = 0;
    for(const char &c: seq){
        result += (int)(c);
        result *= 17;
        result %= 256;
    }
    return result;
}

void solve() {
    string line;cin>>line;

    string curr;

    int ans = 0;

    for(const char &c: line){
        if(c == ',') ans += HASH(curr), curr = "";
        else curr.push_back(c);
    }
    ans += HASH(curr);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
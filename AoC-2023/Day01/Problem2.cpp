#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const map<string, int> strDigit =  {{"one",1},{"two",2},{"three",3},
    {"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};

void solve() {
    long long ans = 0;
    map<char,int> digits;
    for(int i=0;i<10;i++) digits[i+'0'] = i;

    for (int line=1;line<=N;line++) {
        string s;
        getline(cin, s);

        const int n = s.size();
        int first = 0, last = 0;

        for(int i=0;i<n;i++){
            if(digits.count(s[i])){
                last = digits[s[i]];
                if(first == 0) first = digits[s[i]];
            }

            string d = "";

            for(int j=0;j<5;j++){
                if(i+j >= n) break;

                d.push_back(s[i+j]);

                if(strDigit.count(d)){
                    last = strDigit.at(d);
                    if(first == 0) first = strDigit.at(d);
                }
            }
        }
        
        ans += ((10*first) + last);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

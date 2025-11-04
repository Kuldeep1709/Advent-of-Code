#include <bits/stdc++.h>
using namespace std;

const int N = 187;

void solve() {
    map<char,int> digits;
    for(int i=0;i<10;i++) digits[i+'0'] = i;

    unordered_map<int, int> wins; // storing winCount for each card
    priority_queue<int,vector<int>, greater<int>> pq; // min heap to process the game

    for (int card=1;card<=N;card++) {
        pq.push(card);
        string s;
        getline(cin, s);

        const int n = s.size();
        int idx = 0;
        while(s[idx] != ':') idx++;

        unordered_map<string, int> winVals;

        while(s[idx] != '|'){
            if(digits.count(s[idx])){
                string val;
                while(digits.count(s[idx])) val.push_back(s[idx]), idx++;

                winVals[val] = stoi(val);
            }
            idx++;
        }

        int winCount = 0;

        while(idx < n){
            if(digits.count(s[idx])){
                string val;
                while(digits.count(s[idx])) val.push_back(s[idx]), idx++;

                if(winVals.count(val)) winCount++;
            }
            idx++;
        }

        wins[card] = winCount;
    }

    long long ans = N; // initial cards
    
    while(!pq.empty()){
        int curr = pq.top();
        pq.pop();

        ans += (wins[curr]);

        for(int i=1;i<=wins[curr];i++) pq.push(curr+i);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

const map<char, int> cardStrength = {{'J',0}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6},
{'7',7}, {'8',8}, {'9',9}, {'T',10}, {'Q',12}, {'K',13}, {'A',14}};

int handRank(const string &hand){
    map<char,int> freqMap;
    for(const char &c: hand) freqMap[c]++;

    const int n = freqMap.size();
    bool containJ = freqMap.count('J');

    if(n == 1) return 1; // five of a kind
    if(n == 2){
        if(containJ) return 1; // upgrade to 5 of a kind

        if(freqMap[hand[0]] == 1 || freqMap[hand[0]] == 4) return 2; // four of a kind
        if(freqMap[hand[0]] == 2 || freqMap[hand[0]] == 3) return 3; // full house
    }
    if(n == 3){
        vector<int> freq;
        for(const auto &ele: freqMap) freq.push_back(ele.second);

        sort(freq.begin(), freq.end());

        if(freq[0] == 1 && freq[1] == 1 && freq[2] == 3){
            if(containJ) return 2;
            return 4; // three of a kind
        }
        if(freq[0] == 1 && freq[1] == 2 && freq[2] == 2){
            if(containJ){
                if(freqMap['J'] == 1) return 3; // upgrade to full house
                return 2; // upgrade to 4 of a kind
            }
            return 5; // two pair
        }
    }

    if(n == 4){
        if(containJ) return 4; // upgrade to 3 of a kind
        return 6; // one pair
    }

    if(containJ) return 6; // upgrade to 1 pair
    return 7; // high card
}

struct compare {
    bool operator()(const string &a, const string &b) const {
        const int ra = handRank(a);
        const int rb = handRank(b);

        if(ra != rb) return ra < rb;

        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) return cardStrength.at(a[i]) > cardStrength.at(b[i]);
        }

        return false;
    }
};

void solve() {
    map<string, int, compare> handBid;

    for(int line = 1;line <= N; line++){
        string s;
        getline(cin,s);

        string hand = s.substr(0, 5);
        string bid = s.substr(6);

        handBid[hand] = stoi(bid);
    }

    long long ans = 0, rank = N;

    for(auto &[hand, bid]: handBid) ans += bid*(rank--);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

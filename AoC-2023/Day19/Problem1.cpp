#include <bits/stdc++.h>
using namespace std;

unordered_map<string,vector<tuple<char, bool, int, string, string>>> mp;

string flow(int x, int m, int a, int s, string curr){
    for(auto t: mp[curr]){
        char c = get<0>(t);
        bool inq = get<1>(t);
        int num = get<2>(t);
        string curr = get<3>(t);
        string next = get<4>(t);

        if(c == '$'){
            if(next == "A" || next == "R") return next;
            else return flow(x,m,a,s,next);
        }
        else{
            if(c == 'x'){
                bool ok = (inq) ? (x < num) : (x > num);
                if(ok){
                    if(curr == "A" || curr == "R") return curr;
                    return flow(x,m,a,s,curr);
                }
            }
            else if(c == 'm'){
                bool ok = (inq) ? (m < num) : (m > num);
                if(ok){
                    if(curr == "A" || curr == "R") return curr;
                    return flow(x,m,a,s,curr);
                }
            }
            else if(c == 'a'){
                bool ok = (inq) ? (a < num) : (a > num);
                if(ok){
                    if(curr == "A" || curr == "R") return curr;
                    return flow(x,m,a,s,curr);
                }
            }
            else{
                bool ok = (inq) ? (s < num) : (s > num);
                if(ok){
                    if(curr == "A" || curr == "R") return curr;
                    return flow(x,m,a,s,curr);
                }
            }
        }
    }
    return "#";
}

void inputMap(){
    string line;
    while(getline(cin, line)){
        if(line.empty()) break;

        string key;
        int idx = 0, n = line.size();
        while(line[idx] != '{') key.push_back(line[idx++]);

        idx++; // {

        while(idx < n - 4){
            char c = line[idx++];
            bool inq = (line[idx++] == '<');

            string num;
            while(idx < n && line[idx] >= '0' && line[idx] <= '9'){
                num.push_back(line[idx]);
                idx++;
            }
            idx++; // :

            string curr;
            while(idx < n){
                if(line[idx] == ',') break;
                curr.push_back(line[idx]);
                idx++;
            }
            idx++; // ,

            string next;
            if(idx+1 < n && (line[idx+1] != '>' && line[idx+1] != '<')){
                while(idx < n){
                    if(line[idx] == '}') break;
                    next.push_back(line[idx]);
                    idx++;
                }
            }

            mp[key].push_back({c, inq, stoi(num), curr, ""});
            if(next.size()){
                mp[key].push_back({'$', true, -1, "$", next});
            }
        }
    }
}

void solve() {
    inputMap();

    string line;
    long long ans = 0;

    // workflows
    while(getline(cin, line)){
        int idx = 3, n = line.size();
        string num;

        while(idx < n && line[idx] >= '0' && line[idx] <= '9'){
            num.push_back(line[idx]);
            idx++;
        }
        int x = stoi(num);
        num = "";
        idx+=3;

        while(idx < n && line[idx] >= '0' && line[idx] <= '9'){
            num.push_back(line[idx]);
            idx++;
        }
        int m = stoi(num);
        num = "";
        idx+=3;

        while(idx < n && line[idx] >= '0' && line[idx] <= '9'){
            num.push_back(line[idx]);
            idx++;
        }
        int a = stoi(num);
        num = "";
        idx+=3;

        while(idx < n && line[idx] >= '0' && line[idx] <= '9'){
            num.push_back(line[idx]);
            idx++;
        }
        int s = stoi(num);

        string final = flow(x, m, a, s, "in");

        if(final == "A") ans += 1LL*(x+a+m+s);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
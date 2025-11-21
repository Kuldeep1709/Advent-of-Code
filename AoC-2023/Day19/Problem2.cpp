#include <bits/stdc++.h>
using namespace std;

unordered_map<string,vector<tuple<char, bool, int, string, string>>> mp;

long long total(int xl, int xr, int ml, int mr, int al, int ar, int sl, int sr){
    return 1LL*(xr-xl+1)*(mr-ml+1)*(ar-al+1)*(sr-sl+1);
}

void cobminations(int xl, int xr, int ml, int mr, int al, int ar, int sl, int sr, string curr, long long &ans){
    if(curr == "R" || xl > xr || ml > mr || al > ar || sl > sr) return;
    if(curr == "A"){
        ans += total(xl,xr,ml,mr,al,ar,sl,sr);
        return;
    }

    for(auto t: mp[curr]){
        char c = get<0>(t);
        bool inq = get<1>(t);
        int num = get<2>(t);
        string next1 = get<3>(t);
        string next2 = get<4>(t);

        if(c == '$') cobminations(xl, xr, ml, mr, al, ar, sl, sr, next2, ans);
        else{
            if(c == 'x'){
                if(inq) cobminations(xl, num-1, ml, mr, al, ar, sl, sr, next1, ans), xl = num;
                else cobminations(num+1, xr, ml, mr, al, ar, sl, sr, next1, ans), xr = num;
            }
            else if(c == 'm'){
                if(inq) cobminations(xl, xr, ml, num-1, al, ar, sl, sr, next1, ans), ml = num;
                else cobminations(xl, xr, num+1, mr, al, ar, sl, sr, next1, ans), mr = num;
            }
            else if(c == 'a'){
                if(inq) cobminations(xl, xr, ml, mr, al, num-1, sl, sr, next1, ans), al = num;
                else cobminations(xl, xr, ml, mr, num+1, ar, sl, sr, next1, ans), ar = num;
            }
            else if(c == 's'){
                if(inq) cobminations(xl, xr, ml, mr, al, ar, sl, num-1, next1, ans), sl = num;
                else cobminations(xl, xr, ml, mr, al, ar, num+1, sr, next1, ans), sr = num;
            }
        }
    }
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

    cobminations(1,4000,1,4000,1,4000,1,4000, "in", ans);
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
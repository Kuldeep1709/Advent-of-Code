#include <bits/stdc++.h>
using namespace std;

#define ll long long
const map<char, vector<int>> dirs =
{
    {'U', {-1,0}},
    {'D', {1,0}},
    {'L', {0,-1}},
    {'R', {0,1}}
};

long long hexToDec(const string &num){
    int dec = 0;
    for(const char &dig: num){
        dec <<= 4;
        if('0' <= dig && dig <= '9') dec += (dig - '0');
        else dec += (10 + tolower(dig) - 'a');
    }
    return dec;
}

ll area(const vector<pair<int,int>> &points){
    long long A = 0;
    const int n = points.size();

    for(int i=0;i<n;i++){
        int r = (i+1)%n;
        ll xi = points[i].first, yi = points[i].second;
        ll xr = points[r].first, yr = points[r].second;

        A += (xi*yr - xr*yi);
    }

    return llabs(A)/2;
}

void solve() {
    string line;
    long long B = 0;
    vector<pair<int,int>> points = {{0,0}};

    while(getline(cin, line)){
        if(line.empty()) continue;

        string hexcode = line.substr(line.find('#') + 1, 6);

        char dig = hexcode[5];
        ll len = hexToDec(hexcode.substr(0,5));

        char dir;
        if(dig == '0') dir = 'R';
        else if(dig == '1') dir = 'D';
        else if(dig == '2') dir = 'L';
        else dir = 'U';

        int x = points.back().first, y = points.back().second;
        int dx = dirs.at(dir)[0], dy = dirs.at(dir)[1];

        B += len;
        points.push_back({x + len*dx, y + len*dy});
    }

    ll A = area(points);
    ll ans = A - (B/2) + 1 + B; // Pick's Theorem

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
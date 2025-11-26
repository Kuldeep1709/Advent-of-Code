#include <bits/stdc++.h>
using namespace std;

struct Position {
    int sx, sy, sz; // start coordinates
    int ex, ey, ez; // end coordinates
};

bool compare(const Position &a, const Position &b){
    return a.sz < b.sz;
}

vector<int> getNums(const string& s) {
    vector<int> nums;
    string token;
    stringstream ss(s);

    while (getline(ss, token, ',')) {
        if (!token.empty()) {
            nums.push_back(stoi(token));
        }
    }

    return nums;
}

bool haveCommonXY(const Position &a, const Position &b){
    return max(a.sx, b.sx) <= min(a.ex, b.ex) && max(a.sy, b.sy) <= min(a.ey, b.ey);
}

void settle(vector<Position> &bricks){
    const int n = bricks.size();
    for(int i=0;i<n;i++){
        int z = 1;
        for(int j=0;j<i;j++){
            if(haveCommonXY(bricks[i], bricks[j])){
                z = max(z, bricks[j].ez + 1);
            }
        }

        bricks[i].ez -= (bricks[i].sz - z);
        bricks[i].sz = z;
    }
}

int totalFall(const vector<Position> &bricks){
    const int n = bricks.size();
    unordered_map<int, vector<int>> supports;
    unordered_map<int, vector<int>> supportedBy;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (haveCommonXY(bricks[i], bricks[j])){
                if(bricks[i].sz == bricks[j].ez + 1){
                    supports[j].push_back(i);
                    supportedBy[i].push_back(j);
                }
            }
        }
    }

    int total = 0;
    vector<int> remain;
    for(int i=0;i<n;i++) remain.push_back(supportedBy[i].size());

    for(int i=0;i<n;i++){
        queue<int> falling;
        vector<int> left = remain;
        vector<int> fallen(n,false);

        falling.push(i);
        fallen[i] = true;

        while(!falling.empty()){
            int curr = falling.front(); falling.pop();

            for(int &next: supports[curr]){
                left[next]--;
                if(!fallen[next] && left[next] == 0){
                    falling.push(next);
                    fallen[next] = true;
                }
            }
        }

        for(int j=0;j<n;j++) if(fallen[j]) total++;

        total--; // Disintegrated brick is not counted
    }

    return total;
}

void solve(){
    string line;
    vector<Position> bricks;

    while(getline(cin, line)) {
        int idx = line.find('~');
        vector<int> start = getNums(line.substr(0, idx));
        vector<int> end = getNums(line.substr(idx+1));

        Position pos;
        pos.sx = start[0], pos.sy = start[1], pos.sz = start[2];
        pos.ex = end[0], pos.ey = end[1], pos.ez = end[2];

        bricks.push_back(pos);
    }

    sort(bricks.begin(), bricks.end(), compare); // based on staring z
    settle(bricks);
    sort(bricks.begin(), bricks.end(), compare);

    int ans = totalFall(bricks);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
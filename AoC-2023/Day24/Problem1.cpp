#include <bits/stdc++.h>
using namespace std;

const double LEAST = 2e14;
const double MOST  = 4e14;

struct Particle {
    double x, y, z;
    double vx, vy, vz;
};

vector<double> getNums(const string& s) {
    vector<double> nums;
    string token;
    stringstream ss(s);

    while (getline(ss, token, ',')) {
        token.erase(remove(token.begin(), token.end(), ' '), token.end());
        if (!token.empty()) nums.push_back(stod(token));
    }
    return nums;
}

// Not Considering Z coordinate for this part
pair<double, double> solve2D(const Particle& p1, const Particle& p2){
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double vx1 = p1.vx, vy1 = p1.vy;
    double vx2 = p2.vx, vy2 = p2.vy;

    double D = vx1 * vy2 - vy1 * vx2;

    if (fabs(D) < 1e-9) return {-1, -1}; // Parallel lines

    double t1 = ((x2 - x1) * vy2 - (y2 - y1) * vx2) / D;
    double t2 = ((x2 - x1) * vy1 - (y2 - y1) * vx1) / D;

    // must occur in the future for both particles
    if (t1 < 0 || t2 < 0) return {-1, -1};

    double ix = x1 + vx1 * t1;
    double iy = y1 + vy1 * t1;

    return {ix, iy};
}

bool inside(const pair<double,double> &soln) {
    if (soln.first == -1 && soln.second == -1) return false;

    double ix = soln.first;
    double iy = soln.second;

    return ix >= LEAST && ix <= MOST && iy >= LEAST && iy <= MOST;
}

void solve(){
    vector<Particle> particles;
    string line;

    while (getline(cin, line)) {
        size_t idx = line.find('@');

        vector<double> pos = getNums(line.substr(0, idx));
        vector<double> vel = getNums(line.substr(idx + 1));

        particles.push_back({
            pos[0], pos[1], pos[2],
            vel[0], vel[1], vel[2]
        });
    }

    long long ans = 0;
    int n = particles.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pair<double, double> soln = solve2D(particles[i], particles[j]);

            if(inside(soln)) ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
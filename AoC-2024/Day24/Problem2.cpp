#include <bits/stdc++.h>
using namespace std;

// Refrences : https://youtu.be/SU6lp6wyd3I?feature=shared & ChatGPT

unsigned long long Bin_Dec(string s) {
    unsigned long long ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) ans += ((s[i] - '0') * (1ULL << i));
    return ans;
}


string make_wire(char prefix, int num) {
    stringstream ss;
    ss << prefix << setw(2) << setfill('0') << num;
    return ss.str();
}


bool verify_z(map<string, tuple<string, string, string>> &formulas, const string &wire, int num);


bool verify_intermediate_xor(map<string, tuple<string, string, string>> &formulas, const string &wire, int num) {
    if (formulas.find(wire) == formulas.end()) return false;
    auto [op, x, y] = formulas[wire];
    if (op != "XOR") return false;
    return (x == make_wire('x', num) && y == make_wire('y', num)) || 
           (x == make_wire('y', num) && y == make_wire('x', num));
}


bool verify_carry_bit(map<string, tuple<string, string, string>> &formulas, const string &wire, int num) {
    if (formulas.find(wire) == formulas.end()) return false;
    auto [op, x, y] = formulas[wire];

    if (num == 1) {
        return op == "AND" && 
               ((x == "x00" && y == "y00") || (x == "y00" && y == "x00"));
    }

    if (op != "OR") return false;

    auto verify_direct_carry = [&](const string &w, int n) {
        if (formulas.find(w) == formulas.end()) return false;
        auto [op, x, y] = formulas[w];
        return op == "AND" && 
               ((x == make_wire('x', n) && y == make_wire('y', n)) || 
                (x == make_wire('y', n) && y == make_wire('x', n)));
    };

    auto verify_recarry = [&](const string &w, int n) {
        if (formulas.find(w) == formulas.end()) return false;
        auto [op, x, y] = formulas[w];
        return op == "AND" && 
               ((verify_intermediate_xor(formulas, x, n) && verify_carry_bit(formulas, y, n)) || 
                (verify_intermediate_xor(formulas, y, n) && verify_carry_bit(formulas, x, n)));
    };

    return (verify_direct_carry(x, num - 1) && verify_recarry(y, num - 1)) || 
           (verify_direct_carry(y, num - 1) && verify_recarry(x, num - 1));
}


bool verify_z(map<string, tuple<string, string, string>> &formulas, const string &wire, int num) {
    if (formulas.find(wire) == formulas.end()) return false;
    auto [op, x, y] = formulas[wire];
    if (op != "XOR") return false;
    if (num == 0) return (x == "x00" && y == "y00") || (x == "y00" && y == "x00");
    return (verify_intermediate_xor(formulas, x, num) && verify_carry_bit(formulas, y, num)) || 
           (verify_intermediate_xor(formulas, y, num) && verify_carry_bit(formulas, x, num));
}


bool verify(map<string, tuple<string, string, string>> &formulas, int num) {
    return verify_z(formulas, make_wire('z', num), num);
}


int progress(map<string, tuple<string, string, string>> &formulas) {
    int i = 0;
    while (verify(formulas, i)) {
        i++;
    }
    return i;
}

int main() {

    map<string, tuple<string, string, string>> formulas;
    
    string line;
    while (getline(cin, line)) {
        if (line.empty() || line.find("->") == string::npos) continue;
        stringstream ss(line);
        string x, op, y, arrow, z;
        ss >> x >> op >> y >> arrow >> z;
        formulas[z] = make_tuple(op, x, y);
    }

    vector<string> swaps;
    for (int k = 0; k < 4; k++) {
        int baseline = progress(formulas);
        for (auto it1 = formulas.begin(); it1 != formulas.end(); ++it1) {
            for (auto it2 = next(it1); it2 != formulas.end(); ++it2) {
                swap(it1->second, it2->second);
                if (progress(formulas) > baseline) {
                    swaps.push_back(it1->first);
                    swaps.push_back(it2->first);
                    goto next_swap;
                }
                swap(it1->second, it2->second); 
            }
        }
    next_swap:
        continue;
    }

    sort(swaps.begin(), swaps.end());
    for (size_t i = 0; i < swaps.size(); ++i) {
        cout << swaps[i];
        if (i + 1 < swaps.size()) cout << ",";
    }

    cout << "\n";

    return 0;
}

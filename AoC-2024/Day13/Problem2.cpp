#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define n 320

bool LinEqn(ull x1, ull x2, ull y1, ull y2, ull tx, ull ty, ull& a, ull& b) {
    ull den = (x1 * y2 > x2 * y1) ? (x1 * y2 - x2 * y1) : (x2 * y1 - x1 * y2);

    if (den) {
        ull num1 = (tx * y2 > ty * x2) ? (tx * y2 - ty * x2) : (ty * x2 - tx * y2);
        ull num2 = (ty * x1 > tx * y1) ? (ty * x1 - tx * y1) : (tx * y1 - ty * x1);

        if (num1 % den == 0 && num2 % den == 0) {
            ull x = num1 / den;
            ull y = num2 / den;

            if (x >= 0 && y >= 0) {
                a = x;
                b = y;
                return true;
            }
        }
    }
    else {
        if (x1 * ty == x2 * tx && y1 * tx == y2 * ty) {
            ull g = __gcd(x1, x2);
            ull h = x2 / g;
            ull k = x1 / g;

            ull min_a = 0, min_b = 0;
            bool found = false;
            for (ull k = 0;; k++) {
                ull x = k * h;
                if (tx >= x * x1 && (tx - x * x1) % x2 == 0) {
                    ull y = (tx - x * x1) / x2;
                    if (x * y1 + y * y2 == ty) {
                        if (!found || (3 * x + y < 3 * min_a + min_b)) {
                            min_a = x;
                            min_b = y;
                            found = true;
                        }
                    }
                }
                if (3 * k * h + k > 3 * min_a + min_b && found) break;
            }

            if (found) {
                a = min_a;
                b = min_b;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ull ans = 0;

    for (int i = 0; i < n; i++) {
        string a, b, p;
        getline(cin, a);
        getline(cin, b);
        getline(cin, p);
        cin.ignore();

        ull x1 = 0, y1 = 0, x2 = 0, y2 = 0, targetx = 0, targety = 0;

        int j = 12;
        while (a[j] != ',') x1 = (x1 * 10) + (a[j] - '0'), j++;
        j += 4;
        while (j < a.size()) y1 = (y1 * 10) + (a[j] - '0'), j++;

        j = 12;
        while (b[j] != ',') x2 = (x2 * 10) + (b[j] - '0'), j++;
        j += 4;
        while (j < b.size()) y2 = (y2 * 10) + (b[j] - '0'), j++;

        j = 9;
        while (p[j] != ',') targetx = (targetx * 10) + (p[j] - '0'), j++;
        j += 4;
        while (j < p.size()) targety = (targety * 10) + (p[j] - '0'), j++;

        targetx += 1e13;
        targety += 1e13;

        ull h, k;
        bool exist = LinEqn(x1, x2, y1, y2, targetx, targety, h, k);

        if (exist) ans += ((3 * h) + k);
    }

    cout << ans << "\n";

    return 0;
}

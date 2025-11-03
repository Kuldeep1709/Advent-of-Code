#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define n 50
#define m 20

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    vector<string> arr(n), move(m);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> move[i];

    int x = 0, y = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '@') {
                x = i;
                y = j;
                arr[x][y] = '.';
                found = true;
                break;
            }
        }
        if (found) break;
    }

    for (string s : move) {
        for (char c : s) {
            if (c == '^') {
                if (in(x - 1, y) && arr[x - 1][y] == '.')
                    x--;
                else if (in(x - 1, y) && arr[x - 1][y] == 'O') {
                    int j = 2;
                    while (in(x - j, y) && arr[x - j][y] == 'O') j++;
                    if (in(x - j, y) && arr[x - j][y] == '.') {
                        arr[x - j][y] = 'O';
                        arr[x - 1][y] = '.';
                        x--;
                    }
                }
            } else if (c == '>') {
                if (in(x, y + 1) && arr[x][y + 1] == '.')
                    y++;
                else if (in(x, y + 1) && arr[x][y + 1] == 'O') {
                    int j = 2;
                    while (in(x, y + j) && arr[x][y + j] == 'O') j++;
                    if (in(x, y + j) && arr[x][y + j] == '.') {
                        arr[x][y + j] = 'O';
                        arr[x][y + 1] = '.';
                        y++;
                    }
                }
            } else if (c == 'v') {
                if (in(x + 1, y) && arr[x + 1][y] == '.')
                    x++;
                else if (in(x + 1, y) && arr[x + 1][y] == 'O') {
                    int j = 2;
                    while (in(x + j, y) && arr[x + j][y] == 'O') j++;
                    if (in(x + j, y) && arr[x + j][y] == '.') {
                        arr[x + j][y] = 'O';
                        arr[x + 1][y] = '.';
                        x++;
                    }
                }
            } else if (c == '<') {
                if (in(x, y - 1) && arr[x][y - 1] == '.')
                    y--;
                else if (in(x, y - 1) && arr[x][y - 1] == 'O') {
                    int j = 2;
                    while (in(x, y - j) && arr[x][y - j] == 'O') j++;
                    if (in(x, y - j) && arr[x][y - j] == '.') {
                        arr[x][y - j] = 'O';
                        arr[x][y - 1] = '.';
                        y--;
                    }
                }
            }
        }
    }

    ull ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (arr[i][j] == 'O') {
                ans += (100 * i + j);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}

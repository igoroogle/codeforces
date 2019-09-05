#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

bool check(const vector<vector<bool>>& dp, int x, int y, int n, int m) {
    if ((x < 0) || (x >= n) || (y < 0) || (y >= m)) {
        return false;
    }

    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    vector<vector<char>> a;
    vector<vector<bool>> dpUp, dpDown;
    cin >> n >> m;
    a.resize(n);
    dpUp.resize(n);
    dpDown.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        dpUp[i].resize(m);
        dpDown[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    dpUp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                continue;
            }

            if (check(dpUp, i - 1, j, n, m) || check(dpUp, i, j - 1, n, m)) {
                dpUp[i][j] = true;
            }
        }
    }

    if (!dpUp[n - 1][m - 1]) {
        cout << "0\n";
        return 0;
    }

    dpDown[n - 1][m - 1] = true;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (a[i][j] == '#') {
                continue;
            }

            if (check(dpDown, i + 1, j, n, m) || check(dpDown, i, j + 1, n, m)) {
                dpDown[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int vl = 0;
        for (int j = 0; j < m; ++j) {
            if (dpUp[i][j] && dpDown[i][j]) {
                ++vl;
            }
        }

        if (vl < 2) {
            cout << "1\n";
            return 0;
        }
    }


    for (int j = 0; j < m; ++j) {
        int vl = 0;
        for (int i = 0; i < n; ++i) {
            if (dpUp[i][j] && dpDown[i][j]) {
                ++vl;
            }
        }

        if (vl < 2) {
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    return 0;
}

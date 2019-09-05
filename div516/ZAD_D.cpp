#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9;
deque<pair<int, int>> q;
int dp[2002][2002];
char a[2002][2002];
bool use[2002][2002];

bool check(int x, int y, int n, int m) {
    if ((x < 0) || (y < 0) || (x >= n) || (y >= m)) {
        return false;
    }

    if (a[x][y] == '*') {
        return false;
    }

    if (use[x][y]) {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    --r;
    --c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    dp[r][c] = 0;
    q.push_back(mp(r, c));
    int dd;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        if (use[cur.x][cur.y]) {
            continue;
        }
        use[cur.x][cur.y] = true;
        if (check(cur.x + 1, cur.y, n, m)) {
            dd = dp[cur.x + 1][cur.y];
            dp[cur.x + 1][cur.y] = min(dp[cur.x][cur.y], dp[cur.x + 1][cur.y]);
            if (dd != dp[cur.x + 1][cur.y]) {
                q.push_front(mp(cur.x + 1, cur.y));
            }
        }

        if (check(cur.x - 1, cur.y, n, m)) {
            dd = dp[cur.x - 1][cur.y];
            dp[cur.x - 1][cur.y] = min(dp[cur.x][cur.y], dp[cur.x - 1][cur.y]);
            if (dd != dp[cur.x - 1][cur.y]) {
                q.push_front(mp(cur.x - 1, cur.y));
            }
        }

        if (check(cur.x, cur.y + 1, n, m)) {
            dd = dp[cur.x][cur.y + 1];
            if (cur.y < c) {
                dp[cur.x][cur.y + 1] = min(dp[cur.x][cur.y + 1],dp[cur.x][cur.y] + 1);
                if (dd != dp[cur.x][cur.y + 1]) {
                    q.push_back(mp(cur.x, cur.y + 1));
                }

            } else {
                dp[cur.x][cur.y + 1] = min(dp[cur.x][cur.y], dp[cur.x][cur.y + 1]);
                if (dd != dp[cur.x][cur.y + 1]) {
                    q.push_front(mp(cur.x, cur.y + 1));
                }
            }
        }

        if (check(cur.x, cur.y - 1, n, m)) {
            dd = dp[cur.x][cur.y - 1];
            if (cur.y > c) {
                dp[cur.x][cur.y - 1] = min(dp[cur.x][cur.y - 1],dp[cur.x][cur.y] + 1);
                if (dd != dp[cur.x][cur.y - 1]) {
                    q.push_back(mp(cur.x, cur.y - 1));
                }
            } else {
                dp[cur.x][cur.y - 1] = min(dp[cur.x][cur.y], dp[cur.x][cur.y - 1]);
                if (dd != dp[cur.x][cur.y - 1]) {
                    q.push_front(mp(cur.x, cur.y - 1));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[i][j] == INF) {
                continue;
            }

            //cout << i + 1 << ' ' << j + 1 << ' ' << dp[i][j] << ' ' << ans << endl;
            if ((j > c) && (dp[i][j] <= x) && (dp[i][j] + j - c <= y)) {
                a[i][j] = '+';
                ++ans;
            } else  if ((j < c) && (dp[i][j] + c - j <= x) && (dp[i][j] <= y)) {
                ++ans;
                a[i][j] = '+';
            } else if ((j == c) && (dp[i][j] <= min(x, y))) {
                ++ans;
                a[i][j] = '+';
            }

            //cout << ans << endl;
        }
    }

    /*a[r][c] = '+';
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }*/

    cout << ans << '\n';
}

#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const ll INF = 1E10;
ll vl[111][111];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, i, j, bl = 0, ans = INF, sz, i1, j1, kl;
    char c;
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            cin >> c;
            vl[i][j] = vl[i - 1][j] + vl[i][j - 1] - vl[i - 1][j - 1];
            if (c == 'W') {
                ++vl[i][j];
            } else {
                ++bl;
            }
        }
    }

    for (sz = 1; sz <= min(n, m); ++sz) {
        for (i = 1; i <= n - sz + 1; ++i) {
            for (j = 1; j <= m - sz + 1; ++j) {
                i1 = i + sz - 1;
                j1 = j + sz - 1;
                kl = vl[i1][j1] - vl[i1][j - 1] - vl[i - 1][j1] + vl[i - 1][j - 1];
                if (kl + bl == sz * sz) {
                    ans = min(ans, kl);
                }
            }
        }
    }

    if (ans == INF) {
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}

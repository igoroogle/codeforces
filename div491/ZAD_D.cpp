#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[107][5];
char a[3][107];

int main() {
    ios_base::sync_with_stdio(0);
    dp[0][3] = 0;
    dp[0][2] = -1;
    dp[0][1] = -1;
    dp[0][0] = -1;

    int n;
    cin >> a[0] >> a[1];
    n = strlen(a[0]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int p = 0;
        if (a[0][i - 1] == 'X') {
            p |= 1;
        }

        if (a[1][i - 1] == 'X') {
            p |= 2;
        }

        for (int j = 0; j < 4; ++j) {
            if (dp[i - 1][j] == -1) {
                continue;
            }

            dp[i][p] = max(dp[i][p], dp[i - 1][j]);

            if (((j & 1) == 0) && ((j & 2) == 0)) {
                if ((p & 1) == 0) {
                    dp[i][p | 1] = max(dp[i][p | 1], 1 + dp[i - 1][j]);
                }

                if ((p & 2) == 0) {
                    dp[i][p | 2] = max(dp[i][p | 2], 1 + dp[i - 1][j]);
                }
            }

            if (((p & 1) == 0) && ((p & 2) == 0)) {
                if ((j & 1) == 0) {
                    dp[i][3] = max(dp[i][3], 1 + dp[i - 1][j]);
                }

                if ((j & 2) == 0) {
                    dp[i][3] = max(dp[i][3], 1 + dp[i - 1][j]);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}

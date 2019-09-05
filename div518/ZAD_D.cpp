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
const int MOD = 998244353;
int dp[2][203][100003];
int main() {
    ios_base::sync_with_stdio(0);
    //dp[0][0][0] = 1;
    int n, x;
    cin >> n;
    cin >> x;
    if (x == -1) {
        for (int i = 1; i <= 200; ++i) {
            dp[1][i][1] = 1;
        }
    } else {
        dp[1][x][1] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        int y, ans = 0;
        cin >> y;
        if (x != -1) {
            if (y != -1) {
                if (x < y) {
                    dp[1][y][i] = (dp[0][x][i - 1] + dp[1][x][i - 1]) % MOD;
                } else if (x == y) {
                    dp[0][y][i] = (dp[0][x][i - 1] + dp[1][x][i - 1]) % MOD;
                } else {
                    dp[0][y][i] = dp[0][x][i - 1];
                }
            } else {
                for (int j = 0; j <= 200; ++j) {
                    int yy = j;
                    if (x < yy) {
                        dp[1][yy][i] = (dp[0][x][i - 1] + dp[1][x][i - 1]) % MOD;
                    } else if (x == yy) {
                        dp[0][yy][i] = (dp[0][x][i - 1] + dp[1][x][i - 1]) % MOD;
                    } else {
                        dp[0][yy][i] = dp[0][x][i - 1];
                    }
                }
            }
        } else {
            int ss = 0;
            for (int j = 200; j > 0; --j) {
                if ((y == -1) || (y == j)) {
                    dp[0][j][i] = (ss + dp[0][j][i]) % MOD;
                }

                ss = (ss + dp[0][j][i - 1]) % MOD;
            }

            int sml = 0, smr = 0;
            for (int j = 1; j <= 200; ++j) {
                if ((y == -1) || (y == j)) {
                    dp[1][j][i] = (sml + smr) % MOD;
                    dp[0][j][i] = (dp[0][j][i] + dp[0][j][i - 1]) % MOD;
                    dp[0][j][i] = (dp[0][j][i] + dp[1][j][i - 1]) % MOD;
                }

                sml = (sml + dp[0][j][i - 1]) % MOD;
                smr = (smr + dp[1][j][i - 1]) % MOD;
            }
        }
        x = y;
    }

    int ans = 0;
    for (int i = 1; i <= 200; ++i) {
        ans = (ans + dp[0][i][n]) % MOD;
    }
    cout << ans << endl;
}

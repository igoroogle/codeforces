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
const ll MOD = 1000000007;
string s;
int n, x;
ll dp[102][102][102], f[102], prv[102][102][102], suf[102][102][102], seq[102][102][102];
inline void read() {
    cin >> n >> x >> s;
}

inline void prec() {
    f[0] = 2;
    f[1] = 2;
    for (int i = 2; i <= x; ++i) {
        f[i] = (f[i - 1] * f[i - 2]) % MOD;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (static_cast<int>(s[j] - '0') == i) {
                dp[i][j][j] = 1;
                prv[i][j][j] = 1;
                suf[i][j][j] = 1;
                seq[i][j][j] = 1;
            }
        }
    }

}

inline void getAns() {
    for (int k = 2; k <= x; ++k) {
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                seq[k][l][r] = (seq[k - 1][l][r] + seq[k - 2][l][r]) % MOD;
                prv[k][l][r] = (prv[k - 1][l][r] + prv[k - 2][l][r] * f[k - 1]) % MOD;
                suf[k][l][r] = (suf[k - 2][l][r] + suf[k - 1][l][r] * f[k - 2]) % MOD;
                dp[k][l][r] = (f[k - 1] * dp[k - 2][l][r]) % MOD;
                dp[k][l][r] = (dp[k][l][r] + f[k - 2] * dp[k - 1][l][r]) % MOD;
                for (int m = l; m < r; ++m) {
                    seq[k][l][r] = (seq[k][l][r] + seq[k - 1][l][m] * seq[k - 2][m + 1][r]) % MOD;
                    prv[k][l][r] = (prv[k][l][r] + prv[k - 1][l][m] * seq[k - 2][m + 1][r]) % MOD;
                    suf[k][l][r] = (suf[k][l][r] + seq[k - 1][l][m] * suf[k - 2][m + 1][r]) % MOD;
                    dp[k][l][r] = (dp[k][l][r] + prv[k - 1][l][m] * suf[k - 2][m + 1][r]) % MOD;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    read();
    prec();
    getAns();
    cout << dp[x][0][n - 1] << '\n';
}

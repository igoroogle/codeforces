#include<bits/stdc++.h>
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
const ll MOD = 1E9 + 7;
const int LEN = 3E5 + 1;
const int ST = 61;

ll cnk[ST][ST], v_bit[ST], dp[ST][LEN];
int nx[LEN];

inline void prec_cnk() {
    cnk[0][0] = 1;
    for (int i = 1; i < ST; ++i) {
        cnk[i][0] = 1;
        cnk[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % MOD;
        }
    }
}

inline void prec_num(ll k) {
    ++k;
    for (int i = 0; i < ST; ++i) {
        ll cnt_bit = 0;
        for (ll j = ST - 1; j >= 0; --j) {
            if ((ll(1) << j) & k) {
                v_bit[i] = (v_bit[i] + cnk[j][i - cnt_bit]) % MOD;
                ++cnt_bit;
                if (cnt_bit > i) {
                    break;
                }
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    prec_cnk();

    int n, m;
    ll k;
    cin >> n >> m >> k;
    prec_num(k);

    fill(nx, nx + n, n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        nx[l] = min(nx[l], r);
    }

    for (int i = n - 2; i >= 0; --i) {
        nx[i] = min(nx[i + 1], nx[i]);
    }

    for (int i = 0; i < ST; ++i) {
        dp[i][n - 1] = v_bit[i];
    }

    for (int j = n - 2; j >= 0; --j) {
        for (int i = ST - 1; i >= 0; --i) {
            if (nx[j] != nx[j + 1]) {
                dp[i][j] = (dp[i][j] + MOD - dp[i][nx[j]]) % MOD;
            }

            if (i > 0) {
                dp[i - 1][j] = (dp[i - 1][j] + cnk[i][1] * dp[i][j]) % MOD;
            }

            if (j > 0) {
                dp[i][j - 1] = (dp[i][j - 1] + dp[i][j]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < ST; ++i) {
        ans = (ans + dp[i][0]) % MOD;
        cout << i << ' ' << cnk[i][1] << endl;
    }

    cout << ans << '\n';
}

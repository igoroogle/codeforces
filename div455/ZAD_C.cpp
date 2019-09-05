#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll ans[5003];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, ans = 0;
    cin >> n;
    dp[0][0] = 1;
    char c;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= i; ++j) {
            dp2[0][j] = 0;
            dp2[1][j] = 0;
        }

        cin >> c;
        for (ll j = 0; j <= i; ++j) {
            if (dp[0][j] != 0) {
                if (c == 's') {
                    dp2[0][j] = (dp2[0][j] + dp[0][j]) % MOD;
                    if (j > 0) {
                        dp2[0][j - 1] = (dp2[0][j - 1] + dp[0][j]) % MOD;
                    }
                } else {
                    dp2[1][j] = (dp2[1][j] + dp[0][j]) % MOD;
                }
            }

            if (dp[1][j] != 0) {
                if (c == 's') {
                    dp2[0][j + 1] = (dp2[0][j + 1] + dp[1][j]) % MOD;
                } else {
                    dp2[1][j + 1] = (dp2[1][j + 1] + dp[1][j]) % MOD;
                }
            }
        }

        for (ll j = 0; j <= i; ++j) {
            dp[0][j] = dp2[0][j];
            dp[1][j] = dp2[1][j];
        }
    }
}

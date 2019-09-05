#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
const ll DL = 1003;
ll dp[DL][DL], bits[DL], vans[DL];
int main() {
    ios_base::sync_with_stdio(0);
    string s;
    ll k, vl;
    cin >> s >> k;
    if (s.length() == 1) {
        if (k > 0) {
            cout << 0 << endl;
            return 0;
        }
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < DL; ++i) {
        for (int j = i; j != 0; j >>= 1) {
            bits[i] += ll(j & 1);
        }
    }

    vans[1] = 1;
    for (int i = 2; i < DL; ++i) {
        vans[i] = vans[bits[i]] + 1;
    }

    dp[1][0] = 1;
    for (int i = 1; i < DL; ++i) {
        dp[1][i] = 0;
    }

    for (int i = 2; i < DL; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j < DL; ++j) {
            if (vans[i] + 1 == j){
                dp[i][j] = 1;
            }

            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][j]) % MOD;
        }
    }

    ll ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            continue;
        }
        ++vl;
        if (vans[vl] + 1 == k) {
            ans = (ans + 1) % MOD;
        }

        ans = (ans + dp[vl + int(s.length() - i) - 2][k] + MOD - dp[vl][k]) % MOD;
    }

    cout << ans << endl;
}

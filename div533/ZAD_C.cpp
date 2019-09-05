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

ll get_prev(ll r, ll mod) {
    ll ans = r / ll(3);
    if (r % ll(3) == ll(1)) {
        if (mod == ll(1)) {
            ++ans;
        }
    } else if (r % ll(3) == 2) {
        if (mod > ll(0)) {
            ++ans;
        }
    }
    return ans;
}

ll get_interv(ll l, ll r, ll mod) {
    return get_prev(r, mod) - get_prev(l - ll(1), mod);
}

ll vt[3], dp[3][200002];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < 3; ++i) {
        vt[i] = get_interv(l, r, i);
        dp[i][0] = vt[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < 3; ++i) {
            for (int k = 0; k < 3; ++k) {
                dp[(i + k) % ll(3)][j] = (dp[i][j - 1] * vt[k] + dp[(i + k) % ll(3)][j]) % MOD;
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
}

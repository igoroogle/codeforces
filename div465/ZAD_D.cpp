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
const ll MOD = 1E9 + 7;
ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % ll(2) == ll(1))
		return (binpow(a, n - ll(1)) * a) % MOD;
	else {
		ll b = binpow (a, n / ll(2));
		return (b * b) % MOD;
	}
}

ll a[100010], b[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll ans = 0, toans = 1, hans, grans = 0;
    ll n, m, obm;
    cin >> n >> m;
    obm = binpow(m, MOD - ll(2));
    for (ll i = 1; i <= m; ++i) {
        hans = ((m - i) * obm) % MOD;
        hans = (obm * hans) % MOD;
        grans = (grans + hans) % MOD;
    }

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (ll i = 0; i < n; ++i) {
        if ((a[i] != 0) && (b[i] != 0)) {
            if (a[i] == b[i]) {
                continue;
            }

            if (a[i] > b[i]) {
                ans = (ans + toans) % MOD;
            }
            break;
        } else if (b[i] != 0) {
            hans = ((m - b[i]) * obm) % MOD;
            hans = (toans * hans) % MOD;
            ans = (ans + hans) % MOD;
            toans = (toans * obm) % MOD;
        } else if (a[i] != 0) {
            hans = ((a[i] - ll(1)) * obm) % MOD;
            hans = (toans * hans) % MOD;
            ans = (ans + hans) % MOD;
            toans = (toans * obm) % MOD;
        } else {
            hans = (toans * grans) % MOD;
            ans = (ans + hans) % MOD;
            toans = (toans * obm) % MOD;
        }
    }

    cout << ans << '\n';
}

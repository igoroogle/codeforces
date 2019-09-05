#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    ll ans = binpow(a, n / 2);
    ans = (ans * ans) % MOD;
    if (n % 2) {
        ans = a * ans % MOD;
    }
    return ans;
}

ll a[5010];

int main() {
    ll n, k, t, mult = 1, u, v;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mult = mult * a[i] % MOD;
    }

    t = binpow((ll(n - 2 + MOD) % MOD) * binpow(n, MOD - 2), n - 1);
    cout << n - 1 << ' ' << t << endl;
    u = (binpow(t, k) + MOD - ll(1)) % MOD;
    v = (t + MOD - ll(1)) % MOD;
    t = u * binpow(v, MOD - 2) % MOD;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        u = binpow(a[i], MOD - 2) * t % MOD;
        ans = (ans + u) % MOD;
    }
    ans = mult * ans % MOD;
    cout << ans << endl;
}

#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 2000010;
const ll MOD = 1E9 + 7;
ll f[DL], st[DL];
ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }

    ll ans = binpow(a, n >> ll(1));
    ans = ans * ans % MOD;
    if (n & ll(1)) {
        ans = ans * a % MOD;
    }

    return ans;
}

ll get(ll x, ll y, ll vl) {
    ll to = 0;
    while (x % vl == 0) {
        x /= vl;
        ++to;
    }
    return f[y + to - 1] * binpow(f[y - 1] * f[to] % MOD, MOD - 2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    int q;
    ll x, y;
    f[0] = 1;
    st[0] = 1;
    for (ll i = 1; i < DL; ++i) {
        f[i] = f[i - 1] * ll(i) % MOD;
        st[i] = st[i - 1] * ll(2) % MOD;
    }

    ll ans, to, t, i;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        ans = st[y - 1];
        i = 2;
        t = x;
        while (i * i <= t) {
            to = 0;
            while (t % i == 0) {
                t /= i;
                ++to;
            }

            if (to > 0) {
                to = f[y + to - 1] * binpow(f[y - 1] * f[to] % MOD, MOD - 2) % MOD;
                ans = ans * to % MOD;
            }
            ++i;
        }

        if (t > 1) {
            ans = ans * y % MOD;
        }
        cout << ans << '\n';
    }
}

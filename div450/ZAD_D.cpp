#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ll MOD = 1E9 + 7;

ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % ll(2) == ll(1))
		return (binpow(a, n - ll(1)) * a) % MOD;
	else {
		int b = binpow(a, n / ll(2));
		return (b * b) % MOD;
	}
}

ll del(ll a, ll b) {
    return a * binpow(b, ll(MOD - 2)) % MOD;
}


int main() {
    ios_base::sync_with_stdio(0);
    ll x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    y /= x;
    ll ans = 0;
    vector<ll> p;
    ll g = y;
    ll i = 2;
    while (i * i <= g) {
        if (g % i == 0) {
            p.pb(i);
        }
        while (g % i == 0) {
            g /= i;
        }
        ++i;
    }

    if (g > 1) {
        p.pb(g);
    }

	for (int msk = 0; msk < int(1<<p.size()); ++msk) {
		ll mult = 1,
			bits = 0;
		for (int i  =0; i<(int)p.size(); ++i)
			if (msk & (1<<i)) {
				++bits;
				mult *= p[i];
			}

		ll cur = binpow(ll(2), ll(y / mult - 1));
		if (bits % 2 == 1)
			ans = (ans + MOD - cur) % MOD;
		else
			ans = (ans + cur) % MOD;
    }
	cout << ans << endl;
}

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
const ll INF = 1E18;
const ll MOD = 1E9 + 9;

ll binpow (ll a, ll n) {
	if (n == ll(0))
		return ll(1);
	if (n % ll(2) == ll(1))
		return (binpow(a, n - ll(1)) * a) % MOD;
	else {
		ll b = binpow(a, n / ll(2));
		return (b * b) % MOD;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, a, b, k, p, q, qn, b1, fir, las, ans = 0, sm;
    cin >> n >> a >> b >> k;
    p = ll(n + 1) / k;
    string s;
    cin >> s;

    q = (b * binpow(a, MOD - ll(2))) % MOD;
    q = binpow(q, k);
    qn = binpow(q, p);
    for (ll i = 0; i < k; ++i) {
        b1 = (binpow(a, n - i) * binpow(b, i)) % MOD;
        if ((p == 1) || (q == 0)) {
            if (s[i] == '+') {
                ans = (ans + b1) % MOD;
            } else {
                ans = (ans + MOD - b1) % MOD;
            }
            continue;
        }

        if (q == 1) {
            sm = (b1 * p) % MOD;
        } else {
            fir = (ll(1) + MOD - qn) % MOD;
            fir = (b1 * fir) % MOD;
            las = (ll(1) + MOD - q) % MOD;
            sm = (fir * binpow(las, MOD - ll(2))) % MOD;
        }

        if (s[i] == '+') {
            ans = (ans + sm) % MOD;
        } else {
            ans = (ans + MOD - sm) % MOD;
        }
    }
    cout << ans << endl;
}

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
	if (n == ll(0))
		return ll(1);
	if (n % ll(2) == 1)
		return (binpow(a, n - ll(1)) * a) % MOD;
	else {
		ll b = binpow (a, n / ll(2));
		return (b * b) % MOD;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    ll x, k, ans;
    cin >> x >> k;
    if (x == ll(0)) {
        cout << 0 << endl;
        return 0;
    }

    ans = x % MOD;
    ans = (binpow(ll(2), k + ll(1)) * ans) % MOD;
    ans = (ans + MOD - binpow(ll(2), k)) % MOD;
    ans = (ans + ll(1)) % MOD;
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1E9 + 7;
ll binpow (ll a, ll n) {
	if (n == 0)
		return ll(1);
	if (n % ll(2) == ll(1))
		return (binpow(a, n - ll(1)) * a) % MOD;
	else {
		ll b = binpow(a, n / 2);
		return (b * b) % MOD;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    if ((k == -1) && (n % 2 != m % 2)) {
        cout << 0 << endl;
        return 0;
    }

    cout << binpow(binpow(2, ll(n - 1)), m - 1) << endl;
}

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
const ll MOD = 998244353;
const ll DL = 200010;
ll f[200010], a[200010];

ll ff[1000003];
const int DLV = 1000003;

ll get (int n) {
    ll ans = 0;
    for (int i = n; i >= 0; i = ((i + 1) & i) - 1) {
        ans += ff[i];
    }
    return ans;
}

void upd (int ind) {
    for (int i = ind; i < DLV; i = ((i + 1) | i)) {
        ++ff[i];
    }
}


ll binpow (ll a, int n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    f[0] = 1;
    for (int i = 1; i < DL; ++i) {
        f[i] = (f[i - 1] * ll(i)) % MOD;
    }

    int n;
    cin >> n;
    ll x, ans = 0;
    ll k = 0;
    ll r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            ++k;
            continue;
        }
        upd(a[i]);
        ans += get(n) - get(a[i]);
        if (a[i] - get(a[i]))
    }

    ans = ans % MOD;

    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            continue;
        }
    }


    cout << ans  * binpow(f[n - k], int(MOD - 2)) << endl;

}

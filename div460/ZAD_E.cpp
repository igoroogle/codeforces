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
ll a, b, p, x, cik = 0;

ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1) {
		return (binpow(a, n - 1) * a) % p;
	} else {
		ll b = binpow (a, n / 2);
		return (b * b) % p;
	}
}

ll avl[1000100];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> p >> x;
    ll vl = 1, ob, tob;
    tob = binpow(b, p - 2);
    cik = 1;
    while (avl[vl] == 0) {
        avl[vl] = cik;
        vl = (vl * a) % p;
        ++cik;
    }

    vl = 1;
    ll ans = 0;
    for (int i = 0; i < cik; ++i) {
        ob = (b * binpow(vl, p - 2)) % p;
        //ob = (ob + p - i) % p;

        vl = (vl * a) % p;
    }
}

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
const ll INF = 2E18 + 3;
const ll DL = 31623;
ll issqr(ll n) {
    ll sq = ll(sqrt(ld(n)));
    for (ll i = max(sq - ll(2), ll(0)); i < sq + ll(3); ++i) {
        if (i * i == n) {
            return true;
        }
    }
    return false;
}

bool scheck(ll n, ll m, ll x) {
    return ((n > 0) && (n <= 1000000000) && (m > 0) && (m <= 1000000000)
        && (sqr(n) - sqr(max(ll(1), n / m)) == x));
}

bool check(ll a, ll b, ll x) {
    if ((a + b) & ll(1) != 0) {
        return false;
    }

    if ((b - a) & ll(1) != 0) {
        return false;
    }

    ll n = (a + b) >> ll(1), m = 1;
    ll dr = (b - a) >> ll(1);
    ll vl1 = max(n / (dr + ll(1)) - ll(1), ll(1));
    ll vl2 = n / max(ll(1), dr - ll(1)) + ll(2);
    for (ll dm = vl1; dm <= vl2; ++dm) {
        if (scheck(n, dm, x)) {
            cout << n << ' ' << dm << '\n';
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll t, x;
    bool f;
    cin >> t;
    while (t--) {
        cin >> x;
        f = true;
        for (ll i = 1; i * i < x; ++i) {
            if ((x % i == 0) && (check(i, x / i, x))) {
                f = false;
                break;
            }
        }

        if (x == 0) {
            f = false;
            cout << "1 1\n";
        }

        if (f) {
            cout << -1 << '\n';
        }
    }
}

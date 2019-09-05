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
ll check(ll x, ll n, ll k) {
    ll vl = n / x - ll(1);
    vl = vl / k + ll(1);
    return vl;
}

ll checks(ll x, ll n, ll k) {
    return check(x, n, k) * x;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k, m, d, l, r, mm, ans = 0;
    cin >> n >> k >> m >> d;
    l = 1;
    r = m;
    while (l < r) {
        mm = (l + r) >> ll(1);
        if (check(mm, n, k) > d) {
            l = mm + 1;
        } else {
            r = mm;
        }
    }

    if (m < l) {
        cout << 0 << endl;
        return 0;
    }

    for (ll i = l; i <= min(m, l + ll(3)); ++i) {
        ans = max(checks(i, n, k), ans);
    }

    for (ll i = max(l, m - ll(3)); i <= m; ++i) {
        ans = max(checks(i, n, k), ans);
    }


    for (ll i = 1; i <= d; ++i) {
            ll x = n / (k * ll(i - 1) + ll(1));
            if (x > m) {
                x = m;
            }

            if (x == 0 || (((n / x) - 1) / k + 1) != i) {
                continue;
            }

            ans = max(ans, x * i);
    }

    cout << ans << endl;
}

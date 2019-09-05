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
ll a[500010];
ld get(ll n, ll i) {
    ll x = a[n] - a[n - 1];
    return ld(x + a[i]) / ld(i + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll q, x, n = 0, j = 0;
    ll t;
    ld ans = 0;
    cin >> q;
    for (ll i = 1; i <= q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            ++n;
            a[n] = a[n - 1] + x;
            continue;
        }


        x = a[n] - a[n - 1];
        while ((j + ll(1) < n) && (ld(x) - get(n, j + ll(1)) > ld(x) - get(n, j))) {
            ++j;
        }
        ans = max(ans, ld(x) - get(n, j));
        cout << fixed << setprecision(9) << ans << '\n';
    }
}

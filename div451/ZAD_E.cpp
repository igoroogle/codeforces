#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 1000003;
const ll INF = 1E18;
ll a[200010], b[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    bool f;
    ll sq;
    ll x, a1 = 0, b1 = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        a[i] = INF;
        b[i] = INF;
        sq = max(ll(sqrt(ld(x))) - ll(3), ll(0));
        for (ll j = sq; j  <= sq + 4; ++j) {
            if (abs(j * j  - x) < a[i]) {
                a[i] = abs(j * j  - x);
                //cout << j * j << ' ' << x << endl;
            }
        }

        for (ll k = max(ll(0), x - ll(10)); k <= x + ll(10); ++k) {
            f = true;
            for (ll j = max(ll(sqrt(ld(k))) - ll(0), ll(0)); j * j <= k; ++j) {
                if (j * j == k) {
                    f = false;
                    break;
                }
            }
            if (f) {
                b[i] = min(abs(k - x), b[i]);
            }
        }
        if (a[i] == 0) {
            ++a1;
        }

        if (b[i] == 0) {
            ++b1;
        }
    }

    if (a1 == b1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0, i;
    if (a1 > b1) {
        sort(b, b + n);
        for (ll i = 0; i < (n >> ll(1)); ++i) {
            ans += b[i];
        }
        cout << ans << endl;
        return 0;
    }

    sort(a, a + n);
    i = 0;
    for (ll i = 0; i < (n >> ll(1)); ++i) {
            //cout << a[i] << endl;
            ans += a[i];
        }
    cout << ans << endl;
}

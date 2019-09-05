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
typedef unsigned long long ull;
const ull INF = 9223372036854775806;
ll n, t;
pair<pair<ll, ll>, ll> a[200010];
ll ans[200010], kol = 0;
bool check(int x) {
    kol = 0;
    if (x == 0) {
        return true;
    }

    if (x == n + 1) {
        return false;
    }

    ll tt = 0;
    for (ll i = 0; i < n; ++i) {
        if (kol == x) {
            break;
        }

        if (a[i].x.y < x) {
            continue;
        }

        if (tt + a[i].x.x <= t) {
            tt += a[i].x.x;
            ans[kol++] = a[i].y;

        }
    }

    return (kol >= x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x.y >> a[i].x.x;
        a[i].y = i + 1;
    }
    sort(a, a + n);

    ll l = 0, r = n + 1, m;
    while (l < r) {
        m = (l + r) >> ll(1);
        if (check(m)) {
            l = m + ll(1);
        } else {
            r = m;
        }
    }

    check(l - 1);
    cout << l - 1 << endl;
    cout << kol << endl;
    for (int i = 0; i < kol; ++i) {
        cout << ans[i] << ' ';
    }
}

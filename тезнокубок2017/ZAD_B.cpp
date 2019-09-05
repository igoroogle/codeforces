#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2E18;
ll c[200010], v[200010], g[200010], n, k, s, t;
bool prov(ll x) {
    ll ind = 0, tim = 0;
    for (ll i = 0; i < k; ++i) {
        if (g[i] - ind > x)
            return false;

        if ((g[i] - ind) * ll(2) <= x) {
            tim += g[i] - ind;
        } else {
            tim += (g[i] - ind) * ll(2) - ((g[i] - ind) % x);
        }

        ind = g[i];
    }


    if (tim <= t) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ll i, l, r, m, tm;
    cin >> n >> k >> s >> t;
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &c[i], &v[i]);
    }

    for (i = 0; i < k; ++i) {
        scanf("%I64d", &g[i]);
    }

    sort(g, g + k);
    g[k++] = s;

    l = 0; r = 1E9 + 5;
    while (l < r) {
        m = (l + r) >> ll(1);
        if (prov(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    tm = l - 1;
    ll ans = -1;
    for (i = 0; i < n; ++i) {
        if ((v[i] >= tm) && ((ans == -1) || (c[i] < ans))) {
            ans = c[i];
        }
    }

    cout << ans << endl;
}

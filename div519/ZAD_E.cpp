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
vector<int> ed[300010];
pair<ll, ll> vl[300010];
pair<ll, pair<ll, ll>> a[300010];
ll smx[300010], smy[300010];

bool check(int n, int ind, ll x) {
    if (ind > n) {
        return false;
    }

    if (a[ind].x > x) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    ll x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        vl[i] = mp(x, y);
        a[i] = mp(x - y, mp(x, y));
    }

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        smx[i] = smx[i - 1] + a[i].y.x;
        smy[i] = smy[i - 1] + a[i].y.y;
    }
    smx[n + 1] = smx[n];
    smy[n + 1] = smy[n];

    for (int i = 1; i <= n; ++i) {
        auto cur = vl[i];
        ll rzv = cur.x - cur.y;
        int l = 1, r = n + 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(n, m, rzv)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ll ans = smx[l - 1] + smy[n + 1] - smy[l - 1];
        ans += ll(l - 1) * cur.y;
        if (l <= n) {
            ans += ll(n - l + 1) * cur.x;
        }

        ed[i].pb(i);
        for (auto v : ed[i]) {
            ll tt = min(cur.x + vl[v].y, cur.y + vl[v].x);
            ans -= tt;
        }

        cout << ans << ' ';
    }

}

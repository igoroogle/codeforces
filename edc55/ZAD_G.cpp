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
ll a[1010], val[1010];
bool use[1010];

vector<pair<ll, int>> ed[1010];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    set<pair<ll, int>> t;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans -= a[i];
        val[i] = -a[i];
    }

    while(m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        ed[u].em(w, v);
        ed[v].em(w, u);
        val[u] += w;
        val[v] += w;
        ans += w;
    }

    for (int i = 0; i < n; ++i) {
        t.insert(mp(val[i], i));
    }

    while ((!t.empty()) || ((t.begin()->x) > 0)) {
        int v = t.begin()->y;
        for (auto cur : ed[v]) {
            int u = cur.x;
            t.erase(mp(u, ))
        }
    }
}

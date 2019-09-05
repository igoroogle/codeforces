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
const ll INF = 1E18 + 3;
const ll DL = 31623;
set<pair<ll, ll>> q;
vector<ll> g[200010], w[200010];
ll d[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, u, v, x;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> x;
        g[v].pb(u);
        w[v].pb(x + x);
        g[u].pb(v);
        w[u].pb(x + x);
    }

    d[0] = 0;
    q.insert(mp(ll(0), ll(0)));
    for (ll i = 1; i <= n; ++i) {
        cin >> x;
        g[0].pb(i);
        w[0].pb(x);
        d[i] = INF;
        q.insert(mp(INF, i));
    }

    while (!q.empty()) {
        //cout << q.begin()->x << endl;
        v = q.begin()->y;
        //cout << v << endl;
		q.erase(q.begin());

		for (size_t j = 0; j < g[v].size(); ++j) {
			ll to = g[v][j];
            ll len = w[v][j];
			if (d[v] + len < d[to]) {
				q.erase (mp(d[to], to));
				d[to] = d[v] + len;
				q.insert (mp(d[to], to));
			}
		}
	}

	for (ll i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
	}
}

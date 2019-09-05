#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E7;
vector<pair<ll, ll>> ed[1000003], ted[1000003], xed[1000003];
ll color[1000003], kl;
ll vl[1000003], mxans = 0, dp[1000003];
bool use[1000003];
ll ans[1000003];

void dfs(ll v) {
    use[v] = true;
    for (auto u : ed[v]) {
        if (!use[u.first]) {
            dfs(u.first);
        }
    }
    ans[--kl] = v;
}

void dfs2(ll v) {
    use[v] = true;
    color[v] = kl;
    ll nval, x, t;
    for (auto u : ted[v]) {
        if ((!use[u.first]) || (color[u.first] == kl)) {
            x = u.second;
            t = ceil((sqrt(ld(1) + ld(8 * x)) - ld(1)) / ld(2));
            t = max(ll(0), t);
            while (ll(1 + t) * t / ll(2) < x) {
                ++t;
            }

            while (ll(1 + t) * t / ll(2) > x) {
                --t;
            }

            nval = x * ll(t + 1) - ll(t) * ll(t + 1) * ll(t + 2) / ll(6);
            vl[kl] += nval;
        }

        if (!use[u.first]) {
            dfs2(u.first);
        }
    }
}

void dfs3(ll v) {
    use[v] = true;
    for (auto u : ed[v]) {
        if (color[v] != color[u.first]) {
            xed[color[v]].emplace_back(color[u.first], u.second);
        }

        if (!use[u.first]) {
            dfs3(u.first);
        }
    }
}

void dfs4(ll v) {
    use[v] = true;
    dp[v] = vl[v];
    for (auto u : xed[v]) {
        if (!use[u.first]) {
            dfs4(u.first);
        }
        dp[v] = max(dp[v], vl[v] + dp[u.first] + u.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        --u;
        --v;
        ed[u].emplace_back(v, w);
        ted[v].emplace_back(u, w);
    }

    kl = n;
    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        use[i] = false;
    }

    kl = 0;
    for (int i = 0; i < n; ++i) {
        if (!use[ans[i]]) {
            dfs2(ans[i]);
            ++kl;
        }
    }

    for (int i = 0; i < n; ++i) {
        use[i] = false;
    }

    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            dfs3(i);
        }
    }

    for (int i = 0; i < kl; ++i) {
        use[i] = false;
    }

    ll s;
    cin >> s;
    --s;
    dfs4(color[s]);
    cout << dp[color[s]] << endl;
}

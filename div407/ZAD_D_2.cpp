#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> a[1000010];
ll st[1000010], ans = 0;
bool use[1000010], use2[1000010];
map<pair<ll, ll>, bool> tt;
void dfs(ll v) {
    use[v] = true;
    for (auto u : a[v]) {
        if (!use[u]) {
            dfs(u);
        }
    }
}

void dfs2(ll v) {
    ll i, val;
    use[v] = true;
    for (auto u : a[v]) {
        if (!use[u]) {
            dfs2(u);
        }
    }

    val = a[v].size();
    ans += ll(val - 1) * val / ll(2);
}

void dfs3(ll v, ll p) {
    ll i, val;
    if (p == -1) {
        use[v] = true;
    }

    for (auto u : a[v]) {
        if (!use[u]) {
            if (p != -1) {
                if (tt[mp(p, u)]) {
                    //ans -= ll(1);
                }
            }
            else {
                dfs3(u, v);
            }
        }
    }

    if (p == -1) {
        for (auto u : a[v]) {
            if (!use[u]) {
                dfs3(u, -1);
            }
        }
    }
}

int main() {
    ll n, m, i, u, v, x, y, pet = 0;
    cin >> n >> m;
    for (i = 0; i < m; ++i) {
        scanf("%I64d%I64d", &x, &y);
        --x;
        --y;
        if (x != y) {
            st[x] += 2;
            st[y] += 2;
            a[x].pb(y);
            a[y].pb(x);
            tt[mp(x, y)] = 1;
            tt[mp(y, x)] = 1;
        } else {
            ++pet;
            st[x] += 2;
        }
    }

    for (i = 0; i < n; ++i) {
        if (st[i] > 0) {
            x = i;
            break;
        }
    }

    dfs(x);
    for (i = 0; i < n; ++i) {
        if ((st[i] > 0) && (!use[i])) {
            cout << 0 << endl;
            return 0;
        }
    }

    ans += pet * (m - pet);
    ans += pet * ll(pet - 1) / ll(2);
    for (i = 0; i < n; ++i) {
        use[i] = 0;
    }

    dfs2(x);

    for (i = 0; i < n; ++i) {
        use[i] = 0;
    }

    dfs3(x, -1);
    cout << ans << endl;
}

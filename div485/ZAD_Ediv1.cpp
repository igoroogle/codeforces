#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
const int DL = 1E7 + 3;
const int LEN = 100010;
const ll MOD = 1E9 + 7;

int parent[LEN];
ll ans[LEN], minDiv[DL], cnt[DL], a[LEN];
int color[LEN];
vector<int> g[LEN], askInd[LEN], askVal[LEN];
vector<ll> askX[LEN];

int getroot(int v) {
    if (parent[v] != -1) {
        parent[v] = getroot(parent[v]);
        return parent[v];
    } else {
        return v;
    }
}

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

inline void makePrime() {
    for (int i = 0; i < DL; ++i) {
        minDiv[i] = i;
    }

    for (int i = 2; i < DL; ++i) {
        if (minDiv[i] != i) {
            continue;
        }

        for (int j = i + i; j < DL; j += i) {
            minDiv[j] = min(ll(i), minDiv[j]);
        }
    }
}

inline void update(ll x, ll updVal) {
    ll val = 1;
    while (x > 1) {
        if (val % minDiv[x]) {
            val = minDiv[x];
        } else {
            val *= minDiv[x];
        }

        cnt[val] += updVal;
        x /= minDiv[x];
    }
}

ll binpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return a;
    }

    if (n & ll(1)) {
        return (binpow(a, n - 1) * a) % MOD;
    }

    ll ans = binpow(a, n >> ll(1));
    ans = (ans * ans) % MOD;
    return ans;
}

ll getX(ll x) {
    ll ans = 1, val = 1;

    while (x > 1) {
        if (val % minDiv[x]) {
            val = minDiv[x];
        } else {
            val *= minDiv[x];
        }
        ans = (ans * binpow(minDiv[x], cnt[val])) % MOD;
        x /= minDiv[x];
    }

    return ans;
}


inline void push(int u, ll x, int ind, int v) {
    askX[u].pb(x);
    askInd[u].pb(ind);
    askVal[u].pb(v);
}


void dfs(int v) {
    color[v] = 1;
    parent[v] = -1;
    update(a[v], 1);

    for (auto u : g[v]) {
        if (color[u] == 0) {
            dfs(u);
            parent[u] = v;
        }
    }

    for (size_t i = 0; i < askX[v].size(); ++i) {
        ll x = askX[v][i], ind = askInd[v][i];
        ll to = getX(x), u = askVal[v][i];
        if (u == -1) {
            to = binpow(to, MOD - 2);
            to = (to * to) % MOD;
        } else if (color[u] == 2) {
            int p = getroot(u);
            push(p, x, ind, -1);
            ans[ind] = (ans[ind] * gcd(a[p], x)) % MOD;
        }

        ans[ind] = (ans[ind] * to) % MOD;
    }

    update(a[v], -1);
    color[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    makePrime();

    int n, u, v;

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ans[i] = 1;
        ll x;
        cin >> u >> v >> x;
        --u;
        --v;
        if (u == v) {
            ans[i] = gcd(a[v], x);
            continue;
        }

        push(u, x, i, v);
        push(v, x, i, u);
    }

    dfs(0);

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
}

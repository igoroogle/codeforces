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
const ll MOD = 1E9 + 7;
const int DL = 1507;
int f[DL][DL], u[DL][DL], c[DL][DL], a[DL], d[DL], par[DL], qv[2][DL], sm = 0, fval1 = 0, fval2 = 0, fval = 0;
vector<int> ed[DL], eds[2][DL];
vector<pair<int, int>> fn;

inline void add(int t, int u, int v) {
    eds[t][u].pb(v);
    eds[t][v].pb(u);
}

inline void read(int t, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        add(t, u, v);
    }
}

inline void read2(int t) {
    int q;
    cin >> q;
    while (q--) {
        int k, x;
        cin >> k >> x;
        qv[t][k] = x;
    }
}

void dfs(vector<int>& add, int t, int v, int p) {
    d[v] = 0;

    if (qv[t][v] != 0) {
        add.pb(v);
        for (auto u : eds[t][v]) {
            if (u == p) {
                continue;
            }
            dfs(add, t, u, p);
            d[v] += d[u];
        }
        return;
    }

    vector<int> add2;
    add2.pb(v);
    for (auto u : eds[t][v]) {
        if (u == p) {
            continue;
        }

        dfs(add2, t, u, v);
        d[v] += d[u];
    }

    if (d[v] > qv[t][v]) {
        cout << -1 << '\n';
        exit(0);
    }

    if (t == 0) {
        ed[0].pb(sm);
        ed[sm].pb(0);
        u[0][sm] = qv[t][v] - d[v];
        fval1 += qv[t][v] - d[v];
        u[sm][0] = 0;
        for (auto cur : add2) {
            ed[sm].pb(cur);
            ed[cur].pb(sm);
            u[sm][cur] = 1;
            u[cur][sm] = 1;
            c[sm][cur] = -a[cur];
            c[cur][sm] = a[cur];
        }
        ++sm;
        return;
    }

    fn.em(sm, qv[t][v] - d[v]);
    fval2 += qv[t][v] - d[v];
    for (auto cur : add2) {
        ed[cur].pb(sm);
        ed[sm].pb(cur);
        u[cur][sm] = 1;
        u[sm][cur] = 0;
    }
    ++sm;
}


void bellManFlow(int s, int t, int n) {
    fill(d, d + n, 0);
    fill(par, par + n, -1);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int v = 0; v < n; ++v) {
            for (auto to : ed[v]) {
                if (u[v][to] - f[v][to] <= 0) {
                    continue;
                }

                if (d[v] + c[v][to] < d[to]) {
                    d[to] = d[v] + c[v][to];
                    par[to] = v;
                }
            }
        }
    }
}


inline void minCostFlow(int s, int t, int n) {
    int fl = 0, cst = 0;
    while (fl < fval) {
        bellManFlow(s, t, n);
        vector<int> ar;
        ar.pb(t);
        while (par[ar.back()] != -1) {
            ar.pb(par[ar.back()]);
        }
        reverse(ar.begin(), ar.end());
        int mfl = 0;
        for (int i = 0; i < int(ar.size()) - 1; ++i) {
            int v = ar[i];
            int to = ar[i + 1];
            mfl = min(mfl, u[v][to] - f[v][to]);
        }

        fl += mfl;
        for (int i = 0; i < int(ar.size()) - 1; ++i) {
            int v = ar[i];
            int to = ar[i + 1];
            cst += mfl * c[v][to];
            f[v][to] += mfl;
            f[to][v] -= mfl;
        }
    }

    if (fl == fval) {
        cout << -cst << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n >> x >> y;
    sm = n + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    read(0, n);
    read(1, n);
    read2(0);
    read2(1);
    vector<int> addv;
    dfs(addv, 0, x, -1);
    addv.clear();
    dfs(addv, 1, y, -1);
    for (auto cur : fn) {
        ed[cur.x].pb(sm);
        ed[sm].pb(cur.x);
        u[cur.x][sm] = cur.y;
        u[sm][cur.x] = 0;
    }

    if (fval1 != fval2) {
        cout << -1 << '\n';
        return 0;
    }

    fval = fval1;
    minCostFlow(0, sm, sm + 1);
}

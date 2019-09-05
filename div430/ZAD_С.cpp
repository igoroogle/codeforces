#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int DL = 200010;
vector<int> g[DL];
vector<int> a[DL];
int coun[DL], ans[DL], vl[DL];
void dfs(int v, int p, int kol) {
    vector<int> dl;
    int x = vl[v], i, y, val, t;
    for (i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            dl.pb(i);
            if (x / i != i) {
                dl.pb(x / i);
            }
        }
    }

    for (i = 0; i < dl.size(); ++i) {
        t = dl[i];
        if (coun[t] != kol - 1) {
            continue;
        }

        ++coun[t];
        y = coun[t];
        val = max(a[y][a[y].size() - 1], t);
        a[y].pb(val);
    }

    ans[v] = max(a[kol][a[kol].size() - 1], a[kol - 1][a[kol - 1].size() - 1]);
    dl.clear();
    for (i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v, kol + 1);
        }
    }

    for (i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            dl.pb(i);
            if (x / i != i) {
                dl.pb(x / i);
            }
        }
    }

    for (i = dl.size() - 1; i >= 0; --i) {
        t = dl[i];
        if (coun[t] != kol) {
            continue;
        }

        a[coun[t]].pop_back();
        --coun[dl[i]];
    }

    dl.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, i, u, v;
    cin >> n;
    for (i = 0; i < DL; ++i) {
        a[i].pb(0);
    }

    for (i = 0; i < n; ++i) {
        cin >> vl[i];
    }

    for (i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1, 1);
    for (i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}

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

vector<int> ed[200010];
ll dpc[200010], dpnc[200010], klc[200010], klnc[200010];
ll ansc = 0, ansnc = 0, ansklc = 0, ansklnc = 0;

void dfs(int v, int p) {
    ll smc = 0, klcV = 0, smnc = 0, klncV = 0;
    for (auto u : ed[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        ll vl = ll(1) + dpc[u] + klc[u];
        ll tkl = ll(1) + klc[u];

        ansc += smc * tkl +  vl * klcV;
        ansnc += vl;
        ansklnc += tkl * klcV;
        ansklnc += tkl;

        ansc += smnc * tkl + vl * klncV;
        ansklc += tkl * klncV;

        vl = dpnc[u] + klnc[u];
        tkl = klnc[u];
        ansc += smc * tkl + vl * klcV;
        ansc += vl;
        ansklc += tkl * klcV;
        ansklc += tkl;

        ansnc += smnc * tkl + vl * klncV;
        ansklnc += tkl * klncV;

        smnc += ll(1) + dpc[u] + klc[u];
        klncV += ll(1) + klc[u];
        smc += dpnc[u] + klnc[u];
        klcV += klnc[u];
    }

    dpc[v] = smc;
    dpnc[v] = smnc;
    klc[v] = klcV;
    klnc[v] = klncV;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    dfs(0, -1);
    cout << ansc / ll(2) + (ansnc - ansklnc + ll(1)) / ll(2)  + ansklnc << '\n';
}

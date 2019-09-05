#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const int LEN = 150100;

int par[LEN], len[LEN];
vector<int> ed[LEN];
int lef[LEN], rig[LEN];

int getroot(int v) {
    if (par[v] == -1) {
        return v;
    }
    par[v] = getroot(par[v]);
    return par[v];
}


void unions(int u, int v) {
    u = getroot(u);
    v = getroot(v);
    if (len[v] == len[u]) {
        ++len[v];
    } else if (len[u] > len[v]) {
        swap(u, v);
    }
    par[u] = v;
    ed[rig[u]].pb(lef[v]);
    ed[lef[v]].pb(rig[u]);
    lef[v] = lef[u];
}

void dfs(int v, int p) {
    cout << v + 1 << ' ';
    for (auto u : ed[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    fill(par, par + n, -1);
    fill (len, len + n, 0);
    for (int i = 0; i < n; ++i) {
        lef[i] = i;
        rig[i] = i;
    }

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        unions(x, y);
    }
    dfs(lef[getroot(0)], -1);
}

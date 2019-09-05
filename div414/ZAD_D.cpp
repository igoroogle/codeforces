#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll DL = 300010;
vector<ll> ed[DL], vt[DL];
ll val[DL], sq[DL], ans[DL];
ll col[DL];
set<ll> st[DL];
pair<pair<ll, ll>, ll> an[DL];
int cl[DL];
bool use[DL];
void dfs(ll v, ll p) {
    cl[v] = 1;
    for (auto u : vt[v]) {
        if (u == p) {
            continue;
        }

        if (cl[u] == 1) {
            cout << "NO\n";
            exit(0);
        }

        dfs(u, v);
    }
    cl[v] = 2;
}

void ds(ll v, ll pl) {
    use[v] = true;
    for (auto u : vt[v]) {
        if (!use[u]) {
            ans[u] = ans[v] + pl;
            ds(u, pl);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    srand(time(0));
    ll n, m, u, v, i, kl = 1;
    for (i = 0; i < DL; ++i) {
        val[i] =  (ll(rand) << ll(45)) ^ (ll(rand) << ll(30)) ^ (ll(rand) << ll(15)) ^ ll(rand());
        sq[i] =  (ll(rand) << ll(45)) ^ (ll(rand) << ll(30)) ^ (ll(rand) << ll(15)) ^ ll(rand());
    }

    cin >> n >> m;
    for (i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    for (i = 0; i < n; ++i) {
        an[i].y = i;
        st[i].insert(i);
        an[i].x.x += val[i];
        an[i].x.y += sq[i];
        for (auto j : ed[i]) {
            if (st[i].find(j) == st[i].end()) {
                an[i].x.x += val[j];
                an[i].x.y += sq[j];
                st[i].insert(j);
            }
        }
    }

    for (i = 0; i < n; ++i) {
        st[i].clear();
    }

    sort(an, an + n);
    col[an[i].y] = 0;
    for (i = 1; i < n; ++i) {
        col[an[i].y] = col[an[i - 1].y];
        if (an[i].x != an[i - 1].x) {
            ++col[an[i].y];
            kl = col[an[i].y] + 1;
        }
    }

    for (i = 0; i < n; ++i) {
        u = col[i];
        st[u].insert(u);
        for (auto j : ed[i]) {
            v = col[j];
            if (st[u].find(v) == st[u].end()) {
                vt[u].pb(v);
                st[u].insert(v);
            }
        }
    }

    for (i = 0; i < kl; ++i) {
        if (vt[i].size() > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    //dfs(0, -1);
    u = 0;
    ll sm = 0;
    for (i = 0; i < kl; ++i) {
        sm += vt[i].size();
        if (vt[i].size() == 2) {
            u = i;
        }
    }

    if (sm / ll(2) != kl - ll(1)) {
        cout << "NO\n";
        return 0;
    }
    /*for (i = 0; i < n; ++i) {
        cout << i + 1 << ' ' << col[i] << endl;
    }
    cout << u << endl;*/
    ans[u] = 1E8;
    use[u] = true;
    if (vt[u].size() > 0) {
        ans[vt[u][0]] = 1E8 - 1;
        ds(vt[u][0], -1);
    }

    if (vt[u].size() > 1) {
        ans[vt[u][1]] = 1E8 + 1;
        ds(vt[u][1], 1);
    }

    cout << "YES\n";
    for (i = 0; i < n; ++i) {
        cout << ans[col[i]] << ' ';
    }
}

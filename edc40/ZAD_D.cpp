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
typedef unsigned int uni;
const ll INF = 1E18;
vector<int> ed[1010];
ll d1[1010], d2[1010];
bool use1[1010], use2[1010];
bool vl[1003][1003];
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, s, t, u, v;
    cin >> n >> m >> s >> t;
    --s;
    --t;
    while (m--) {
        cin >> u >> v;
        --u;
        --v;
        vl[u][v] = true;
        vl[v][u] = true;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    for (int i = 0; i < 1010; ++i) {
        d1[i] = INF;
        d2[i] = INF;
    }
    d1[s] = 0;
    d2[t] = 0;
    for(;;) {
        int ind = -1;
        for (int i = 0; i < n; ++i) {
            if ((!use1[i]) && (d1[i] != INF) && ((ind == -1) || (d1[ind] > d1[i]))) {
                ind = i;
            }
        }

        if (ind == -1) {
            break;
        }
        use1[ind] = true;

        for (auto u : ed[ind]) {
            if (d1[ind] + 1 < d1[u]) {
                d1[u] = d1[ind] + 1;
            }
        }
    }

    for(;;) {
        int ind = -1;
        for (int i = 0; i < n; ++i) {
            if ((!use2[i]) && (d2[i] != INF) && ((ind == -1) || (d2[ind] > d2[i]))) {
                ind = i;
            }
        }

        if (ind == -1) {
            break;
        }
        use2[ind] = true;

        for (auto u : ed[ind]) {
            if (d2[ind] + 1 < d2[u]) {
                d2[u] = d2[ind] + 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == j) || (vl[i][j])) {
                continue;
            }
            if ((d1[i] + 1 + d2[j] >= d1[t]) && (d1[j] + 1 + d2[i] >= d1[t])) {
                //cout << i + 1 << ' ' << j + 1 << ' ' << d1[i] << ' ' << d2[j] << ' ' << d1[t] << endl;
                vl[i][j] = true;
                vl[j][i] = true;
                ++ans;
            }
        }
    }
    cout << ans << endl;
}

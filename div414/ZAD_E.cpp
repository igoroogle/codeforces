#include<bits/stdc++.h>
#include<vector>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> ed[20010], vl[20010];
int cur[40010];
bool use[40010];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, i, u, v, kl;
    cin >> n >> m;
    for (i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        t[u].pb(1);
        vl[u].pb(i);
        ed[v].pb(u);
        t[v].pb(1);
        vl[v].pb(i);
    }

    for (i = 0; i < n; ++i) {
        if (ed[i].size() & 1) {
            ans.pb(i);
        }
    }

    kl = m;
    for (i = 0; i < ans.size() - 2; i += 2) {
        ed[ans[i]].pb(ans[i + 1]);
        t[ans[i]].pb(0);
        vl[ans[i]].pb(kl);
        ed[ans[i + 1]].pb(ans[i]);
        t[ans[i + 1]].pb(0);
        vl[ans[i + 1]].pb(kl);
        // cout << " rb " << ans[i] + 1 << ' ' << ans[i + 1] + 1 << endl;
        ++kl;
    }

    cout << kl - m + 1 << endl;
    if (kl > m) {
        v  = ans[ans.size() - 1];
    } else {
        v = 0;
    }
    ans.clear();
    ans.pb(v);
    tp.pb(0);
    // cout << v + 1 << endl;
    while (!ans.empty()) {
        v = ans[ans.size() - 1];
        while (cur[v] < ed[v].size()) {
            if (!use[vl[v][cur[v]]]) {
                use[vl[v][cur[v]]] = true;
                ans.pb(ed[v][cur[v]]);
                // cout << ed[v][cur[v]] + 1 << " d ";
                tp.pb(t[v][cur[v]]);
                ++cur[v];
                break;
            } else {
                ++cur[v];
            }
        }
        // cout << v + 1 << " df\n";
        if (v == ans[ans.size() - 1]) {
            // cout << v + 1 << " ff\n";
            // cout << v + 1 << " df ";
            cout << v + 1;
            if (tp[tp.size() - 1] == 0) {
                cout << endl;
            } else {
                cout << ' ';
            }
            // cout << ' ';
            ans.pop_back();
            tp.pop_back();
        }
    }
}

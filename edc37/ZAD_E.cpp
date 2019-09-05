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
vector<int> g[200010];
bool use[200010];
int comp[200010];
vector<int> ans;
map<pair<int, int>, bool> t;
list<int> del;
vector<int> add;
int main() {
    ios_base::sync_with_stdio(0);
    int n, m, u, v, kl = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
        t[mp(u, v)] = true;
        t[mp(v, u)] = true;
    }

    for (int i = 0; i < n; ++i) {
        del.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (use[i]) {
            continue;
        }
        use[i] = true;
        ans.pb(1);
        add.clear();
        add.pb(i);
        size_t j = 0;
        while (j < add.size()) {
            v = add[j];
            auto cur = del.begin();
            while (cur != del.end()) {
                auto ncur = cur;
                ++ncur;
                if (use[*cur]) {
                    del.erase(cur);
                } else if (!t[mp(v, *cur)]) {
                    add.pb(*cur);
                    use[*cur] = true;
                    ++ans.back();
                    del.erase(cur);
                }
                cur = ncur;
            }
            ++j;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}

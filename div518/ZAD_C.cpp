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
vector<pair<int, int>> a[111];
vector<int> ed[111];
bool use[111];
vector<int> st[111];

int main() {
    ios_base::sync_with_stdio(0);
    int x = 0, y = 0, n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        ed[u].pb(v);
        ed[v].pb(u);
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (use[i]) {
            continue;
        }
        q.push(i);
        while (!q.empty()) {
            auto val = q.front();
            q.pop();
            if (use[val]) {
                continue;
            }
            use[val] = true;

            st[val].pb(y);
            ++y;
            for (auto cur : st[val]) {
                a[val].pb(mp(x, cur));
            }
            int xs = x;
            ++x;
            for (auto cur : ed[val]) {
                if (use[cur]) {
                    continue;
                }
                a[val].pb(mp(xs, y));
                a[cur].pb(mp(x, y));
                st[cur].pb(y);
                ++x;
                ++y;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i].size() << '\n';
        for (auto cur : a[i]) {
            cout << cur.x + 1 << ' ' << cur.y + 1 << '\n';
        }
    }
}

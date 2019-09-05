#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
set<pair<int, int>> pr, vl;
pair<int, int> ls[200010];
vector<int> ed[200010], ans;
int kl[200010];

void add(pair<int, int> v) {
    ed[v.x].pb(v.y);
    ed[v.y].pb(v.x);
    pr.insert(mp(min(v.x, v.y), max(v.x, v.y)));
    vl.erase(mp(kl[v.x], v.x));
    vl.erase(mp(kl[v.y], v.y));
    ++kl[v.x];
    ++kl[v.y];
    vl.insert(mp(kl[v.x], v.x));
    vl.insert(mp(kl[v.y], v.y));
}

void reb(pair<int, int> v) {
    auto pnt = pr.find(mp(min(v.x, v.y), max(v.x, v.y)));
    if (pnt == pr.end()) {
        return;
    }
    pr.erase(pnt);
    vl.erase(mp(kl[v.x], v.x));
    vl.erase(mp(kl[v.y], v.y));
    --kl[v.x];
    --kl[v.y];
    vl.insert(mp(kl[v.x], v.x));
    vl.insert(mp(kl[v.y], v.y));
}

int des(int v) {
    for (auto u : ed[v]) {
        reb(mp(v, u));
    }
    kl[v] = 0;
    vl.erase(mp(0, v));
}

int gAns(int k) {
    while ((!vl.empty()) && ((vl.begin()->x) < k)) {
        des(vl.begin()->y);
    }
    return vl.size();
}


int main() {
    ios_base::sync_with_stdio(0);
    pair<int, int> pp;
    int n, m, k, u, v;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        auto cur = mp(u, v);
        --u;
        --v;
        add(cur);
        ls[i] = cur;
    }

    for (int i = m - 1; i >= 0; --i) {
        ans.pb(gAns(k));
        reb(ls[i]);
    }

    reverse(ans.begin(), ans.end());
    for (auto cur : ans) {
        cout << cur << '\n';
    }
}

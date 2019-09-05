#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E7;
vector<ll> vl[3000003];
vector<ll> sm[3000003];
ll l[3000003], n;
void dfs(ll v) {
    if (v > n) {
        return;
    }

    dfs(v * 2);
    dfs(v * 2 + 1);
    vector<ll> a = vl[v * 2], b = vl[v * 2 + 1];
    vl[v].resize(a.size() + b.size() + 1);

    for (auto& cur : a) {
        cur += l[v * 2 - 1];
        if (cur > INF) {
            cur = INF;
        }
    }

    for (auto& cur : b) {
        cur += l[v * 2];
        if (cur > INF) {
            cur = INF;
        }
    }

    merge(a.begin(), a.end(), b.begin(), b.end(), vl[v].begin() + 1);
    sm[v].resize(vl[v].size());
    for (size_t i = 1; i < sm[v].size(); ++i) {
        sm[v][i] = sm[v][i - 1] + ll(vl[v][i]);
    }
}

bool check(int v, int h, int ind) {
    if (ind >= vl[v].size()) {
        return false;
    } else {
        return vl[v][ind] < h;
    }
}

ll get_ans(ll v, ll h) {
    ll lf, rg, md;
    if ((v > n) || (h <= 0)) {
        return 0;
    }
    lf = 0;
    rg = vl[v].size();
    while (lf < rg) {
        md = (lf + rg) >> 1;
        if (check(v, h, md)) {
            lf = md + 1;
        } else {
            rg = md;
        }
    }

    return ll(h) * ll(lf) - sm[v][lf - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    ll m;
    cin >> n >> m;
    for (ll i = 1; i < n; ++i) {
        cin >> l[i];
    }

    dfs(1);
    ll a, h, v, u, p, way;
    ll ans;
    while (m--) {
        cin >> a >> h;
        ans = 0;
        ans += max(ll(0), get_ans(a, h));
        p = a;
        v = a / 2;
        way = l[a - 1];
        while (v > 0) {
            if (v * 2 == p) {
                u = v * 2 + 1;
            } else {
                u = v * 2;
            }
            if (h - way > 0) {
                ans += h - way;
            }

            ans += max(ll(0), get_ans(u, max(h - way - l[u - 1], ll(0))));
            p = v;
            way = min(INF, way + l[v - 1]);
            v = v / 2;
        }
        cout << ans << endl;
    }
}

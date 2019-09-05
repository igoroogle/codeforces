#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define pf push_front
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
int r[300005], vl[300005], n, kl = 0;
vector<pair<int, int>> ed[1300005], edb[1300005];

void build (int v, int l, int r) {
    kl = max(kl, v);
    if (l == r) {
        vl[l] = v;
        return;
    }

    int m = (l + r) >> 1;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    ed[v].em(v + v, 0);
    ed[v].em(v + v + 1, 0);
}

void upd(int v, int l, int r, int l1, int r1, int u) {
    if (l > r) {
        return;
    }

    if ((l == l1) && (r == r1)) {
        ed[u].em(v, 1);
        return;
    }

    int m = (l + r) >> 1;
    upd(v + v, l, m, l1, min(r1, r), u);
    upd(v + v + 1, m + 1, r, max(m + 1, l1), r1, u);
}

void add(int v, int l, int r) {
    if (l <= 0) {
        upd(1, 1, n, n + l, n, vl[v]);
        l = 1;
    }

    if (r > n) {
        upd(1, 1, n, r - n, n, vl[v]);
        r = n;
    }

    upd(1, 1, n, l, r, vl[v]);
}

void bfs(int v, vector<int>& dist) {
    dist.resize(kl + 1);
    fill(dist.begin(), dist.end(), n + 1);
    deque<int> q;
    q.pb(v);
    dist[v] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto cur : edb[u]) {
            if (dist[cur.x] != n + 1) {
                continue;
            }

            dist[cur.x] = dist[u] + cur.y;
            if (cur.y) {
                q.pb(cur.x);
            } else {
                q.pf(cur.x);
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> r[i];
        r[n + i] =
    }
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        add(i, i - x, i + x);
    }

    for (int i = 1; i <= kl; ++i) {
        for (auto cur : ed) {
            edb[cur.x].em(i, cur.y);
        }
    }

    vector<int> d1, d2;
    bfs(vl[1], d1);
    bfs(vl[n], d2);
    for (int i = 0;)
}

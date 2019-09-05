#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define int ll
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1E9 + 7;
const int LEN = 300010;
const int VLEN = 800020;
int leav[LEN], mnLeav[LEN], mxLeav[LEN], d[LEN], par[LEN], leavLen = 1;
int t[VLEN];
vector<int> ed[LEN],  q[LEN];
vector<pair<int, int>> seg[LEN];

void dfs(int v) {
    if (ed[v].empty()) {
        mnLeav[v] = leavLen;
        mxLeav[v] = leavLen;
        seg[leavLen].em(leavLen, 1);
        q[leavLen - 1].pb(1);
        ++leavLen;
        d[v] = 1;
        return;
    }

    d[v] = 1;
    for (auto u : ed[v]) {
        dfs(u);
        d[v] += d[u];
        mnLeav[v] = min(mnLeav[u], mnLeav[v]);
        mxLeav[v] = max(mxLeav[u], mxLeav[v]);
    }

    seg[mxLeav[v]].em(mnLeav[v], d[v]);
    q[mnLeav[v] - 1].pb(mxLeav[v] - mnLeav[v] + 1);
}


void upd(int v, int l, int r, int ind, int x) {
    if (l == r) {
        t[v] = max(x, t[v]);
        return;
    }

    int m = (l + r) >> 1;
    if (ind <= m) {
        upd(v + v, l, m, ind , x);
    } else {
        upd(v + v + 1, m + 1, r, ind, x);
    }

    t[v] = max(t[v + v], t[v + v + 1]);
}

int get(int v, int l, int r, int tl, int tr) {
    if (tl > tr) {
        return 0;
    }

    if ((l == tl) && (r == tr)) {
        return t[v];
    }

    int m = (l + r) >> 1;
    return max(get(v + v, l, m, tl, min(tr, m)), get(v + v + 1, m + 1, r, max(tl, m + 1), tr));
}

int getV(int v, int l, int r, int ind) {
    if (l == r) {
        return l;
    }

    int m = (l + r) >> 1;
    if (t[v + v] >= ind) {
        return getV(v + v, l, m, ind);
    } else {
        return getV(v + v + 1, m + 1, r, ind);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    fill(mxLeav, mxLeav + LEN, -INF);
    fill(mnLeav, mnLeav + LEN, INF);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> par[i];
        --par[i];
        ed[par[i]].pb(i);
    }

    dfs(0);

    map<pair<int, int>, int> ans;
    ++leavLen;


    /*for (int i = 0; i < leavLen; ++i) {
        for (auto cur : q[i]) {
            cout << i << ' ' << cur << endl;
        }
    }
    return 0;*/


    //cout << endl;
    for (int i = 1; i < leavLen; ++i) {
        for (auto cur : seg[i]) {
            int vl = ans[mp(cur.x - 1, i - cur.x + 1)];
            //cout << cur.x << ' ' << i << ' ' << vl << ' ' << cur.x - 1 << ' ' << i - cur.x + 1 << endl;
            upd(1, 1, leavLen, i - cur.x + 1, vl + cur.y);
            //cout <<  ans[mp(cur.x - 1, i - cur.x + 1)] << endl;
        }

        for (auto cur : q[i]) {
            ans[mp(i, cur)] = get(1, 1, leavLen, 1, cur);
            //cout << "v " << i << ' ' << cur << endl;
            //cout << ans[mp(i, cur)] << endl;
        }
    }

    //cout << endl;
    for (int i = 1; i <= n; ++i) {
        //cout << i << ' ' << get(1, 1, leavLen, 1, i) << endl;
        cout << getV(1, 1, leavLen, i) << ' ';
    }
}

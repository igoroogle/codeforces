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

template<typename T> class sparceTable {
 public:
    sparceTable() {
        clear();
    }

    sparceTable(T first, T last, function<T(T, T)> g) {
        clear();
        rebuild(first, last, g);
    }

    template<typename It> sparceTable(It first, It last, function<T(T, T)> g) {
        clear();
        rebuild(first, last, g);
    }


    void rebuild(T first, T last, function<T(T, T)> g) {
        f = g;
        sp.resize(1);
        for (auto i = first; i != last; ++i) {
            sp[0].push_back(i);
        }
        build();
    }

    template<typename It> void rebuild(It first, It last, function<T(T, T)> g) {
        f = g;
        sp.resize(1);
        for (auto i = first; i != last; ++i) {
            sp[0].push_back(*i);
        }
        build();
    }

    T get(int l, int r) {
        int lgLen = lgV[r - l + 1];
        return f(sp[lgLen][l], sp[lgLen][r - (1 << lgLen) + 1]);
    }

    void clear() {
        sp.clear();
        lgV.clear();
    }



private:
    function<T(T, T)> f;
    vector<vector<T>> sp;
    vector<int> lgV;
    int n, lgSz;
    void build() {
        n = sp[0].size();
        lgSz = 0;
        lgV.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            if ((1 << (lgSz + 1)) == i) {
                ++lgSz;
            }
            lgV[i] = lgSz;
        }

        sp.resize(lgSz + 1);
        for (int i = 1; i <= lgSz; ++i) {
            sp[i].resize(n);
            for (int j = 0; j < n; ++j) {
                if (j + (1 << (i - 1)) < n) {
                    sp[i][j] = f(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
                } else {
                    sp[i][j] = sp[i - 1][j];
                }
            }
        }
    }
};


sparceTable<pair<int, int>> indSp, tinSp, toutSp;
sparceTable<int>  lcaSp;

vector<int> ed[100010];
int h[200010], indVal[100010];
pair<int, int> ord[200010], tin[200010], tout[200010];

int timVal = 0, ordVal = 0;

void dfs(int v, int hVal) {
    h[v] = hVal;
    indVal[v] = ordVal;
    ord[ordVal++] = mp(hVal, v);
    tin[v] = mp(timVal++, v);
    for (auto u : ed[v]) {
        dfs(u, hVal + 1);
        ord[ordVal++] = mp(hVal, v);
    }
    tout[v] = mp(timVal++, v);
}

int lca(int u, int v) {
    int l = indVal[u];
    int r = indVal[v];
    if (l > r) {
        swap(l, r);
    }

    auto ind = indSp.get(l, r);
    return ind.y;
}



int getTin(int l, int r) {
    return tinSp.get(l, r).y;
}

int getTout(int l, int r) {
    return toutSp.get(l, r).y;
}

int lcaSeg(int l, int r) {
    //return lcaSp.get(l, r);
    return lca(getTin(l, r), getTout(l, r));
}

int getH(int v, int l, int r) {
    if (v == l) {
        return h[lcaSeg(l + 1, r)];
    } else if (v == r) {
        return h[lcaSeg(l, r - 1)];
    } else {
        return h[lca(lcaSeg(l, v - 1), lcaSeg(v + 1, r))];
    }
}

pair<int, int> getAns(int l, int r) {
    int tinV = getTin(l, r);
    int toutV = getTout(l, r);
    return max(mp(getH(tinV, l, r), tinV), mp(getH(toutV, l, r), toutV));
}



int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ed[x].pb(i);
    }
    dfs(0, 0);

    tinSp.rebuild(tin, tin + n,
                    [](pair<int, int> a, pair<int, int> b) {
                        return min(a, b);
                    });

    toutSp.rebuild(tout, tout + n,
                    [](pair<int, int> a, pair<int, int> b) {
                        return max(a, b);
                    });

    indSp.rebuild(ord, ord + ordVal,
                    [](pair<int, int> a, pair<int, int> b) {
                        return min(a, b);
                    });

   lcaSp.rebuild(0, n, [](int a, int b) {
                    return lca(a, b);
                    });


    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        auto ans = getAns(l, r);
        cout << ans.y + 1 << ' ' << ans.x << '\n';
    }
}

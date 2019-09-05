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
const int INF = 1E9 + 7;
const int MODIV = 224;
const int BLEN = 708;
const int LEN = 500002;
const int QLEN = 300002;
set<int> setInd, setTo;
int bLef[BLEN], bRig[BLEN], bval[LEN], mx[LEN], bmx[BLEN], a[LEN], add[LEN], del[LEN],
    lMod[MODIV], rMod[MODIV], lef[LEN], rig[LEN], to[LEN], ans[QLEN];
vector<pair<int, pair<int, int>>> ask;
set<int> lVal[LEN], rVal[LEN];
pair<int, int timPos[LEN];
pair<int, int> timA[LEN];

inline void precalc() {
    //setInd.reserve(MODIV);
    ask.reserve(QLEN);
    fill(ans, ans + QLEN, INF);
    lval.insert(INF);
    rval.insert(INF);
    for (int i = 0; i < BLEN; ++i) {
        bLef[i] = i * BLEN;
        bRig[i] = bLef[i] + BLEN;
    }
    bRig[BLEN - 1] = LEN;

    for (int i = 0; i < LEN; ++i) {
        bval[i] = i / BLEN;
    }
}

inline void rebuild() {
    for (auto ind : setInd) {
        timPos[ind].clear();
    }

    for (auto cur : setTo) {
        to[cur] = rig[cur];
    }

    setInd.clear();
    ask.clear();
    setTo.clear();
}

inline void del(int ind) {
    auto lf  = lef[ind];
    auto rf = rig[ind];
    if (lf != -INF) {
        rig[lf] = rf;
    }

    if (rf != INF) {
        lef[rf] = lf;
    }

    lVal[x].erase(-ind);
    rVal[x].erase(ind);
}

inline void add(ind ind, int x) {
    auto lf  = -(*lVal[x].upper_bound(-ind));
    auto rf = *rVal[x].upper_bound(ind);
    if (lf != -INF) {
        rig[lf] = ind;
    }

    if (rf != INF) {
        lef[rf] = ind;
    }

    lef[ind] = lf;
    rig[ind] = rf;
    lVal[x].insert(-ind);
    rVal[x].insert(ind);
    a[ind] = x;
}

inline void upd(int t, int ind, int x) {
    setInd.insert(ind);
    timePos[ind].em(t, x);
    del(ind);
    add(ind, x);

    if (lef[ind] != -INF) {
        to[lef[ind]] = min(to[lef[ind]], ind);
        setTo.insert(lef[ind]);
    }

    to[ind] = min(rig[ind], to[ind]);
    setTo.insert(ind);

    lMod[t] = lef[ind];
    rMod[t] = rig[ind];
}

inline void updMax(int ind, int x) {
    mx[ind] = x;
    int bvl = bval[ind];
    if (x > bmx[bvl]) {
        bmx[bvl] = x;
    }
}

inline void getMax(int r) {
    int bNum;
    for (bNum = 0; bmx[bNum] <= r; ++bNum);
    for (bNum = bLef[bNum]; mx[bNum] <= r; ++bNum);
    return bNum;
}

inline void getAns(int n) {
    fill(bmx, bmx + BLEN, 0);
    fill(mx, mx + LEN, 0);

}

int main() {
    ios_base::sync_with_stdio(0);
    precalc();
    int n, x;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        add(i, x);
    }

    int askLen = 0, t = 0;

    char type = '';
    while(q--) {
        cin >> type;
        if (type == '?') {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            ask.em(askLen++, mp(l, r));
            continue;
        }

        int ind, x;
        cin >> ind >> x;
        if (t == MODIV) {
            getAns(n);
            upd(++t, ind, x);
            rebuild();
            t = 0;
            continue;
        }

        upd(++t, ind, x);
    }
    getAns(n);

    for (int i = 0; i < askLen; ++i) {
        cout << ans[i] << '\n';
    }
}

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 2E9 + 3;
const int LEN = 524289;
const int ELEN = 10;

pii t[ELEN][LEN];
int a[LEN];
int pw[ELEN];

void precalc_pw() {
    pw[0] = 1;
    for (int i = 1; i < ELEN; ++i) {
        pw[i] = pw[i - 1] * 10;
    }
}

bool check(int bit, int val) {
    return (val / pw[bit] % 10);
}



pii combine(pii a, pii b) {
    pii ans = mp(min(a.x, b.x), max(a.x, b.x));
    auto mn = min(a.y, b.y);
    if (mn < ans.y) {
        ans.y = mn;
    }

    return ans;
}


void build (int bit, int a[], int v, int tl, int tr) {
    if (tl == tr) {
       if (check(bit, a[tl])) {
           t[bit][v] = mp(a[tl], INF);
       } else {
           t[bit][v] = mp(INF, INF);
       }
    } else {
        int tm = (tl + tr) / 2;
        build (bit, a, v*2, tl, tm);
        build (bit, a, v*2+1, tm+1, tr);
        t[bit][v] = combine(t[bit][v*2], t[bit][v * 2 + 1]);
    }
}

void update (int bit, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        if (check(bit, new_val)) {
            t[bit][v] = mp(new_val, INF);
        } else {
            t[bit][v] = mp(INF, INF);
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (bit, v*2, tl, tm, pos, new_val);
        else
            update (bit, v*2+1, tm+1, tr, pos, new_val);
        t[bit][v] = combine(t[bit][v*2], t[bit][v * 2 + 1]);
    }
}

pii get (int bit, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return mp(INF, INF);

    if (l == tl && r == tr) {
        return t[bit][v];
    }

    int tm = (tl + tr) / 2;
    return combine(get(bit, v*2, tl, tm, l, min(r,tm)),
            get(bit, v*2+1, tm+1, tr, max(l,tm+1), r));
}

int main() {
    ios_base::sync_with_stdio(0);
    precalc_pw();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < ELEN; ++i) {
        build(i, a, 1, 1, n);
    }

    while(m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int ind, x;
            cin >> ind >> x;
            for (int i = 0; i < ELEN; ++i) {
                update(i, 1, 1, n, ind, x);
            }
        } else {
            int l, r;
            cin >> l >> r;
            int ans = INF;
            for (int i = 0; i < ELEN; ++i) {
                pii cur = get(i, 1, 1, n, l, r);
                if (cur.y == INF) {
                    continue;
                }

                ans = min(ans, cur.x + cur.y);
            }
            if (ans == INF) {
                ans = -1;
            }

            cout << ans << '\n';
        }
    }
}

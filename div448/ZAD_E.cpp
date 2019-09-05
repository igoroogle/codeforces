#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int a[100010];
ld t[400010], add1[400010], add2[400010];

void build (int l, int r, int v) {
    add1[v] = 1;
    add2[v] = 0;
    if (l == r) {
        t[v] = ld(a[l - 1]);
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, v + v);
    build(m + 1, r, v + v + 1);
    t[v] = t[v + v] + t[v + v + 1];
}

void push(int v, int l, int r) {
    t[v] = t[v] * add1[v] + add2[v] * ld(r - l + 1);
    add1[v + v] *= add1[v];
    add1[v + v + 1] *= add1[v];
    add2[v + v] = add2[v + v] * add1[v] + add2[v];
    add2[v + v + 1] = add2[v + v + 1] * add1[v] + add2[v];
    add1[v] = 1;
    add2[v] = 0;
}

ld get(int l, int r, int v, int l1, int r1) {
    if (l1 > r1) {
        return 0;
    }

    if ((l == l1) && (r == r1)) {
        return t[v] * add1[v] + add2[v] * ld(r - l + 1);
    }

    push(v, l, r);
    int m = (l + r) >> 1;
    return get(l, m, v + v, l1, min(r1, m)) +
    get(m + 1, r, v + v + 1, max(m + 1, l1), r1);

}

void upd(int l, int r, int v, int l1, int r1, ld x, ld y) {
    if (l1 > r1) {
        return;
    }

    if ((l == l1) && (r == r1)) {
        add1[v] *= x;
        add2[v] = add2[v] * x + y;
        return;
    }

    push(v, l, r);
    int m = (l + r) >> 1;
    upd(l, m, v + v, l1, min(r1, m), x, y);
    upd(m + 1, r, v + v + 1, max(m + 1, l1), r1, x, y);
    t[v] = get(l, m, v + v, l, m)
        + get(m + 1, r, v + v + 1, m + 1, r);

}

int main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l1, r1, l2, r2, t, l, r;
    build(1, n, 1);
    ld sm1, sm2;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> l1 >> r1 >> l2 >> r2;
            sm1 = get(1, n, 1, l1, r1) / ld(r1 - l1 + 1);
            sm2 = get(1, n, 1, l2, r2) / ld(r2 - l2 + 1);
            upd(1, n, 1, l1, r1, ld(r1 - l1) / ld(r1 - l1 + 1), sm2 / ld(r1 - l1 + 1));
            upd(1, n, 1, l2, r2, ld(r2 - l2) / ld(r2 - l2 + 1), sm1 / ld(r2 - l2 + 1));
            //cout << sm1 << ' ' << sm2 << ' ' << ld(r1 - l1) / ld(r1 - l1 + 1) << ' ' << sm2 / ld(r1 - l1 + 1) << ' ' << sm1 / ld(r1 - l1 + 1);
            //cout << endl;
            /**for (int i = 0; i < n; ++i) {
                cout << get(1, n, 1, i + 1, i + 1) << ' ';
            }*/
            //cout << endl;
            //cout << get(1, n, 1, 1, n) << ' ' << "sum\n";
        } else {
            cin >> l >> r;
            cout << fixed << setprecision(6) << get(1, n, 1, l, r) << '\n';
        }
    }
}

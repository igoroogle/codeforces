#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[524291], a[200003];

void build (int v, int l, int r) {
    if (l == r) {
        t[v] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    t[v] = t[v + v] + t[v + v + 1];
}

void upd(int v, int l, int r, int ind, ll x) {
    if (l == r) {
        t[v] = x;
        return;
    }

    int m = (l + r) >> 1;
    if (ind <= m) {
        upd(v + v, l, m, ind, x);
    } else {
        upd(v + v + 1, m + 1, r, ind, x);
    }

    t[v] = t[v + v] + t[v + v + 1];
}

int get(int v, int l, int r, ll sum, ll pr) {
    if (l == r) {
        if (a[l] == t[v] + pr - a[l]) {
            return l;
        }
        return -1;
    }

    int m = (l + r) >> 1, val;

    if (t[v + v] + pr >= sum) {
        val = get(v + v, l, m, sum, pr);
    } else {
        return get(v + v + 1, m + 1, r, sum, pr + t[v + v]);
    }

    if (val != -1) {
        return val;
    }

    return get(v + v + 1, m + 1, r, (t[v + v] + pr) * ll(2), pr + t[v + v]);
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    int p;
    ll x;
    while(q--) {
        cin >> p >> x;
        a[p] = x;
        upd(1, 1, n, p, x);
        cout << get(1, 1, n, ll(0), ll(0)) << '\n';
    }
}

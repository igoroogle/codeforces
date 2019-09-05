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

ll t[800010], a[200010];

void build (int v, int l, int r) {
    if (l == r) {
        t[v] = a[l - 1];
        return;
    }
    int m = (l + r) >> 1;
    build(v + v, l, m);
    build(v + v + 1, m + 1, r);
    t[v] = t[v + v] + t[v + v + 1];
}

ll get(int v, int l, int r, ll sum) {
    if (l == r) {
        ll vl = t[v];
        t[v] = 0;
        return vl;
    }

    int m = (l + r) >> 1;
    ll vl = 0;
    if (t[v + v] > sum) {
        vl = get(v + v, l, m, sum);
    } else {
        vl = get(v + v + 1, m + 1, r, sum - t[v + v]);
    }

    t[v] = t[v + v] + t[v + v + 1];
    return vl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    ll t, sm = 0, vl;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }

    build(1, 1, n);
    ll el = n;
    ll ans = 0;
    while (el > 0) {
        vl = t / sm;
        ans += vl * el;
        t -= vl * sm;
        sm -= get(1, 1, n, t);
        --el;
    }
    cout << ans << '\n';
}

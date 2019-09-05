#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

ll f[200010], vl[200010], val[200010];
pair<pair<ll,ll>, ll> a[200010];
ll kl = 0;
map<ll, ll> t;
ll get(int r) {
    ll ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans = max(f[i], ans);
    }
    return ans;
}

void upd(int r, ll x) {
    for (int i = r; i < kl; i = i | (i + 1)) {
        f[i] = max(f[i], x);
    }
}


int main() {
    ll n, i, a1, b1, h1;
    cin >> n;
    vl[kl++] = 0;
    for (i = 0; i < n; ++i) {
        scanf("%I64d%I64d%I64d", &a1, &b1, &h1);
        a[i] = mp(mp(b1, a1), h1);
        vl[kl++] = a1;
        vl[kl++] = b1 - 1;
    }

    sort(vl, vl + kl);
    ll kl2 = 1;
    t[vl[0]] = 0;
    for (i = 1; i < kl; ++i) {
        if (vl[i] != vl[i - 1]) {
            t[vl[i]] = kl2;
            vl[kl2++] = vl[i];
        }
    }

    kl = kl2;
    ll ind, indv, h, j;
    sort(a, a + n);
    reverse(a, a + n);
    for (i = 0; i < n; ++i) {
        ind = t[a[i].x.x - 1];
        indv = t[a[i].x.y];
        h = get(ind);
        if (val[indv] < h + a[i].y) {
            val[indv] = h + a[i].y;
            upd(indv, val[indv]);
        }
    }

    cout << get(kl - 1) << endl;
}

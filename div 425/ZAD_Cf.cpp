#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1E-9;
ll n, s;
vector<ll> v[1000010], t[1000010];
bool an[1000100];
bool check(ld tt) {
    ld ss, vv, ras;
    ll i, j, mn = 0;
    for (i = 1; i < 1000000; ++i) {
        for (j = 0; j < v[i].size(); ++j) {
            if (t[i][j] == 1) {
                continue;
            }

            ss = s;
            vv = v[i][j];
            ras = 1000000 - vv;
            if (tt * (vv + ss) - ras / ss >= 0) {
                mn = max(mn, i + ll(tt * (vv + ss) - ras / ss));
            }
        }

        if (mn >= i) {
            an[i] = true;
        }
    }

    mn = 1000000;
    for (i = 999999; i > 0; --i) {
        for (j = 0; j < v[i].size(); ++j) {
            if (t[i][j] == 2) {
                continue;
            }

            ss = s;
            vv = v[i][j];
            ras = vv;
            if (tt * (vv + ss) - ras / ss >= 0) {
                mn = min(mn, i - ll(tt * (vv + ss) - ras / ss));
            }
        }

        if (mn <= i) {
            if (an[i]) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cout << ll(ld(4.99999)) << endl;
    cin >> n >> s;
    ll i, xx, vv, tt;
    for (i = 0; i < n; ++i) {
        cin >> xx >> vv >> tt;
        v[xx].pb(vv);
        t[xx].pb(tt);
    }

    ld l = 0, r = 1E7, m;
    while (r - l > EPS) {
        m = (l + r) / ld(2);
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(8) << (r + l) / ld(2) << endl;
}

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1E18;
const ld EPS = 1E-12;
ll x[1003];
ld y[1003];
bool check(ll n, ld xx, ld yy, ld r) {
    if (abs(yy) < EPS) {
        return false;
    }

    for (ll i = 0; i < n; ++i) {
        if (abs(sqr(ld(ld(x[i]) - xx)) + sqr(ld(y[i] - yy)) - r) < EPS) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, r;
    ld lf, rf, m;
    cin >> n >> r;
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (ll i = 0; i < n; ++i) {
        y[i] = 1E9;
        lf = 0;
        rf = 1E9;
        while (rf - lf > EPS) {
            m = (lf + rf) / ld(2);
            if (check(i, ld(x[i]), y[i] - m, ld(r))) {
                lf = m;
            } else {
                rf = m;
            }
        }
        y[i] -= (lf + rf) / ld(2);
    }

    for (ll i = 0; i < n; ++i) {
        cout << fixed << setprecision(9) << y[i] << ' ';
    }
}

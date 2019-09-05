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

int main() {
    ios_base::sync_with_stdio(0);
    ll n, r;
    ld vl, d, a, b, c, ans;
    cin >> n >> r;
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (ll i = 0; i < n; ++i) {
        y[i] = r;
        for (ll j = 0; j < i; ++j) {
            if (sqr(ld(x[i] - x[j])) <= sqr(ll(2) * r)) {
                c = -sqr(ll(2) * r) + sqr(ld(x[i] - x[j])) + sqr(y[j]);
                b = -(ld(2) * ld(y[j]));
                a = ld(1);
                d = sqr(b) - ld(4) * a * c;
                if (d < 0) {
                    d = 0;
                }
                ans = max((-b + sqrt(d)) / ld(2), (-b - sqrt(d)) / ld(2));
                y[i] = max(ans, y[i]);
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << fixed << setprecision(9) << y[i] << ' ';
    }
}

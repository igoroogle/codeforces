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
const ll INF = 1E9 + 3;
bool check(ll k, ll d, ll t, ll x) {
    if (ll(sqrt(ld(k))) * ll(sqrt(ld(x))) > INF) {
        return false;
    }

    if (k * x > t) {
        return false;
    }

    if (ll(sqrt(ld(x))) * ll(sqrt(ld(d - k)) / ld(2)) > INF) {
        return false;
    }

    if (ll(2) * k * x + x * (d - k) >= ll(2) * t) {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll k, d, t;
    cin >> k >> d >> t;
    d = ((k - ll(1)) / d + ll(1)) * d;
    ll l = 1, r = t, m;
    while (l < r) {
        m = (l + r) >> ll(1);
        if (check(k, d, t, m)) {
            l = m + ll(1);
        } else {
            r = m;
        }
    }
    --l;
    if (ll(2) * k * (l + ll(1)) + (d - k) * l + ll(2) * k >= ll(2) * t) {
        cout << fixed << setprecision(11) << ld(d * l) + ld(t) - ld(k * l) - ld((d - k) * l) / ld(2) << endl;
    } else {
        cout << fixed << setprecision(11) <<  ld(d) * ld(l + ld(1)) - ld(l + ld(1)) * k - ld(l + ld(1)) * (d - k) / ld(2) + ld(2) * ld(t) << endl;
    }
}

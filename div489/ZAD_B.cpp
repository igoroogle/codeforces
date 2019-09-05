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

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    y /= x;
    ll ans = 0;
    for (ll i = 1; i * i <= y; ++i) {
        if (y % i == 0) {
            ll a = i;
            ll b = y / i;
            if (gcd(a, b) != ll(1)) {
                continue;
            }
            a *= x;
            b *= x;
            if ((min(a, b) >= l) && (max(a, b) <= r)) {
                ++ans;
                if (a != b) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}

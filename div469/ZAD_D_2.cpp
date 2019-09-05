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
int a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, q, x, val, m;
    cin >> n >> q;
    while (q--) {
        cin >> x;
        val = 1;
        m = n;
        bool f = true;
        while (x > 1) {
            if (x & ll(1)) {
                cout << val + (x >> ll(1)) << '\n';
                f = false;
                break;
            }
            val += ((m - ll(1)) >> ll(1)) + ll(1);
            if (m & ll(1)) {
                x  = (ll(x - ll(1)) >> ll(1));
            } else {
                x = (x >> ll(1));
            }
            m -= ((m - ll(1)) >> ll(1)) + ll(1);
            if (x == 0) {
                x = m;
            }
        }

        if (f) {
            cout << val << '\n';
        }
    }
}

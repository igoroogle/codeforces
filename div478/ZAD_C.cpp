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
ll sm[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, q, x, l, r, m, vl = 0;
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> x;
        sm[i] = sm[i - 1] + x;
    }

    while(q--) {
        cin >> x;
        vl += x;
        if (vl >= sm[n]) {
            vl = 0;
            cout << n << '\n';
            continue;
        }

        l = 1;
        r = n;
        while (l < r) {
            m = (l + r) >> ll(1);
            if (vl >= sm[m]) {
                l = m + ll(1);
            } else {
                r = m;
            }
        }

        cout << n - l + ll(1) << '\n';
    }

}

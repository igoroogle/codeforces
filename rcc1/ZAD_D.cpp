#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef unsigned int uni;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0);
    map<uni, uni> t;
    t[0] = 1;
    uni x, y, sm = 0, n, k;
    cin >> n >> k;
    ll ans = ll(n) * ll(n + 1) / ll(2);

    for (int i = 1; i <= n; ++i) {
        cin >> x;
        y = ((1 << k) - 1) & (~x);
        int vl1 = t[sm ^ x], vl2 = t[sm ^ y];
        if (vl2 < vl1) {
            x = y;
        }
        sm ^= x;
        ans -= ll(t[sm]);
        ++t[sm];
    }

    cout << ans << '\n';
}

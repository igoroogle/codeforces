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
const ll MDL = 3E9;
const ll INF = 2E18 + 1;
ll a[200010];
int main() {
    ios_base::sync_with_stdio(0);
    ll n, q, p, x, ans = 0;
    set<pair<ll, ll>> t;
    t.insert(mp(INF, INF));

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
        t.insert(mp(a[i], ll(i)));
    }

    while (q--) {
        cin >> p >> x;
        --p;
        ans -= a[p];
        t.erase(mp(a[p], p));
        t.insert(mp(x, p));
        ans += x;
        a[p] = x;
        if (ans % ll(2)) {
            cout << -1 << '\n';
            continue;
        }

        auto cur = t.lower_bound(mp(ans / ll(2), -ll(1)));
        if (cur->x != ans / ll(2)) {
            cout << -1 << '\n';
            continue;
        }
        cout << cur->y + ll(1) << '\n';
    }
}

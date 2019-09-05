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
const ll INF = 1E18;

pair<pair<ll, ll>, ll> a[300010];

int main() {
    ios_base::sync_with_stdio(0);
    ll n, l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        a[i] = mp(mp(l, -r), i);
    }

    sort(a, a + n);

    set<pair<ll, ll>> t;
    t.insert(mp(-a[0].x.y, a[0].y));
    t.insert(mp(INF, INF));
    for (int i = 1; i < n; ++i) {
        auto cur = *t.lower_bound(mp(-a[i].x.y, 0));
        if (cur.x != INF) {
            cout << a[i].y + ll(1) << ' ' << cur.y + ll(1) << '\n';
            return 0;
        }
        t.insert(mp(-a[i].x.y, a[i].y));
    }
    cout << "-1 -1\n";
}

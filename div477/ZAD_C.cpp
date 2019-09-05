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

ll getUp(ll x1, ll y1, ll x2, ll y2, ll upt, ll v) {
    ll ans = abs(x1 - x2);
    if (ans % v == 0) {
        ans = ans / v;
    } else {
        ans = ans / v + ll(1);
    }
    ans += abs(y1 - upt) + abs(y2 - upt);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    ll n, m, cl, ce, v, x, x1, y1, x2, y2;
    cin >> n >> m >> cl >> ce >> v;
    set<ll> liftl, liftr, upsl, upsr;
    liftl.insert(INF);
    liftl.insert(-INF);
    liftr.insert(INF);
    liftr.insert(-INF);
    upsl.insert(INF);
    upsl.insert(-INF);
    upsr.insert(INF);
    upsr.insert(-INF);

    for (int i = 0; i < cl; ++i) {
        cin >> x;
        upsr.insert(x);
        upsl.insert(-x);
    }

    for (int i = 0; i < ce; ++i) {
        cin >> x;
        liftr.insert(x);
        liftl.insert(-x);
    }

    ll q, ans;
    cin >> q;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans = INF;
        if (x1 == x2) {
            ans = abs(y1 - y2);
        }

        x = *liftr.lower_bound(y1);
        if (x != INF) {
            ans = min(ans, getUp(x1, y1, x2, y2, x, v));
        }

        x = *liftr.lower_bound(y2);
        if (x != INF) {
            ans = min(ans, getUp(x1, y1, x2, y2, x, v));
        }

        x = *liftl.lower_bound(-y1);
        if (x != INF) {
            x = -x;
            ans = min(ans, getUp(x1, y1, x2, y2, x, v));
        }

        x = *liftl.lower_bound(-y2);
        if (x != INF) {
            x = -x;
            ans = min(ans, getUp(x1, y1, x2, y2, x, v));
        }


        x = *upsr.lower_bound(y1);
        if (x != INF) {
            ans = min(ans, getUp(x1, y1, x2, y2, x, ll(1)));
        }

        x = *upsr.lower_bound(y2);
        if (x != INF) {
            ans = min(ans, getUp(x1, y1, x2, y2, x, ll(1)));
        }

        x = *upsl.lower_bound(-y1);
        if (x != INF) {
            x = -x;
            ans = min(ans, getUp(x1, y1, x2, y2, x, ll(1)));
        }

        x = *upsl.lower_bound(-y2);
        if (x != INF) {
            x = -x;
            ans = min(ans, getUp(x1, y1, x2, y2, x, ll(1)));
        }

        cout << ans << '\n';
    }
}

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

pair<ll, ll> inter(ll l1, ll r1, ll l2, ll r2) {
    return mp(max(l1, l2), min(r1, r2));
}

ll lenV (ll x1, ll y1, ll x2, ll y2) {
    if ((x2 < x1) || (y2 < y1)) {
        return ll(0);
    }

    return (x2 - x1 + ll(1)) * (y2 - y1 + ll(1));
}

bool getColor(ll x, ll y) {
    return (abs(x - y) % ll(2));
}

ll getBlack(ll x1, ll y1, ll x2, ll y2) {
    if ((x1 > x2) || (y1 > y2)) {
        return ll(0);
    }


    ll len = lenV(x1, y1, x2, y2);
    ll ans = len / ll(2);
    if ((len % ll(2)) && (getColor(x1, y1))) {
        ++ans;
    }
    return ans;
}

ll getWhite(ll x1, ll y1, ll x2, ll y2) {
    if ((x1 > x2) || (y1 > y2)) {
        return ll(0);
    }


    ll len = lenV(x1, y1, x2, y2);
    ll ans = len / ll(2);
    if ((len % ll(2)) && (!getColor(x1, y1))) {
        ++ans;
    }
    return ans;
}

pair<ll, ll> getAns(ll n, ll m, ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll ansb = 0, answ = 0;
    ansb += getBlack(ll(1), ll(1), m, n);
    answ += getWhite(ll(1), ll(1), m, n);
    ansb -= getBlack(x1, y1, x2, y2);
    answ -= getWhite(x1, y1, x2, y2);
    ansb -= getBlack(x3, y3, x4, y4);
    answ -= getWhite(x3, y3, x4, y4);
    auto p1 = inter(x1, x2, x3, x4);
    auto p2 = inter(y1, y2, y3, y4);
    ansb += getBlack(p1.x, p2.x, p1.y, p2.y);
    answ += getWhite(p1.x, p2.x, p1.y, p2.y);

    answ += lenV(x1, y1, x2, y2) - lenV(p1.x, p2.x, p1.y, p2.y);
    ansb += lenV(x3, y3, x4, y4);
    //cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << endl;
    return mp(answ, ansb);
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        auto ans = getAns(n, m, x1, y1, x2, y2, x3, y3, x4, y4);
        cout << ans.x << ' ' << ans.y << '\n';
    }
}

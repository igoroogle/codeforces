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

struct line {
    ll a, b, c;

    line (ll a1, ll b1, ll c1) {
        a = a1;
        b = b1;
        c = c1;
    }

    line(ll x1, ll y1, ll x2, ll y2) {
        a = y1 - y2;
        b = x2 - x1;
        c = -(a * x1 + b * y1);
    }
};

void add(vector<pair<ld, ld>>& v, line v1, line v2) {
    if (v1.a * v2.b == v1.b * v2.a) {
        return;
    }

    ld d = v1.a * v2.b - v1.b * v2.a;
    ld x = (v1.b * v2.c - v1.c * v2.b) / d;
    ld y = (v2.a * v1.c - v1.a * v2.c) / d;
    v.em(x, y);
}

ld p(pair<ld, ld> p1, pair<ld, ld> p2) {
    return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

int main() {
    ios_base::sync_with_stdio(0);
    vector<pair<ld, ld>> v1, v2;
    pair<ll, ll> p1, p2;
    ll a, b, c;
    cin >> a >> b >> c;
    line lOwn(a, b, c);
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    line l1(p1.x, p1.y, p1.x + 1, p1.y);
    line l2(p1.x, p1.y, p1.x, p1.y + 1);
    line l3(p2.x, p2.y, p2.x + 1, p2.y);
    line l4(p2.x, p2.y, p2.x, p2.y + 1);
    add(v1, lOwn, l1);
    add(v1, lOwn, l2);
    add(v2, lOwn, l3);
    add(v2, lOwn, l4);
    ld ans = abs(p1.x - p2.x) + abs(p1.y - p2.y);
    for (auto cur : v1) {
        for (auto cur2 : v2) {
            //cout << fixed << setprecision(4) << cur.x << ' ' << cur.y << ' ' << cur2.x << ' ' << cur2.y << endl;
            /*ans = min(ans, hypot(ld(p1.x) - cur.x, ld(p1.y) - cur.y)
                      + hypot(cur.x - cur2.x, cur.y - cur2.y)
                        + hypot(cur2.x - ld(p2.x), cur.y - ld(p2.y)));*/
            ans = min(ans, p(mp(ld(p1.x), ld(p1.y)), cur) + p(cur, cur2) + p(cur2, mp(ld(p2.x), ld(p2.y))));
            //cout << p(mp(ld(p1.x), ld(p1.y)), cur) + p(cur, cur2) + p(cur2, mp(ld(p2.x), ld(p2.y))) << endl;
        }
    }

    cout << fixed << setprecision(11) << ans << endl;
}

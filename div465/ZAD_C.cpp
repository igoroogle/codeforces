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
const ld EPS = 1E-10;
const int DL = 203;
ll rr, x1, y1, x2, y2;
bool check(ld& x, ld& y, ld& r) {
    //cout << x << ' ' << y << ' ' << r << endl;
    if (r > rr) {
        return false;
    }

    if (sqr(ld(x2) - x) + sqr(ld(y2) - y) < r * r) {
        return false;
    }

    if (sqr(ld(x1) - x) + sqr(ld(y1) - y)  > ld(rr) * ld(rr)) {
        return false;
    }

    if (sqr(ld(x1) - x) + sqr(ld(y1) - y)  > sqr(ld(rr) - ld(r))) {
        return false;
    }

    return true;
}

ld bin_r(ld& x, ld& y, ld& r) {
    ld l1 = 0, r1 = ld(rr), m;
    for (int i = 0; i < DL; ++i) {
        m = (l1 + r1) / ld(2);
        if (check(x, y, m))
            l1 = m;
        else
            r1 = m;
    }

    r = (l1 + r1) / ld(2);
    return r;
}

ld ter_y(ld& x, ld& y, ld& r) {
    ld l1 = ld(y1) - ld(rr), r1 = ld(y1) + ld(rr), m1, m2;
    for (int i = 0; i < DL; ++i) {
        m1 = l1 + (r1 - l1) / ld(3),
        m2 = r1 - (r1 - l1) / ld(3);
        if (bin_r(x, m1, r) < bin_r(x, m2, r))
            l1 = m1;
        else
            r1 = m2;
    }
    y = (l1 + r1) / ld(2);
    return bin_r(x, y, r);
}

ld ter_x(ld& x, ld& y, ld& r) {
    ld l1 = ld(x1) - ld(rr), r1 = ld(x1) + ld(rr), m1, m2;
    for (int i = 0; i < DL; ++i) {
        m1 = l1 + (r1 - l1) / ld(3),
        m2 = r1 - (r1 - l1) / ld(3);
        if (ter_y(m1, y, r) < ter_y(m2, y, r))
            l1 = m1;
        else
            r1 = m2;
    }
    x = (l1 + r1) / ld(2);
    return ter_y(x, y, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> rr >> x1 >> y1 >> x2 >> y2;
    ld x, y, r;
    ter_x(x, y, r);
    cout << fixed << setprecision(8) << x << ' ' << y << ' ' << r << '\n';
}

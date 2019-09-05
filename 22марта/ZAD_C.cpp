#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#define sqr(a) (a)*(a)
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1E-4;
const ll INF = 1E18;
int a[3], b[3], r[3], n, sx, sy;
ld ras(ld x, ld y, ld x1, ld y1, ld r);
ld ansvec(ld x, ld y, ld x1, ld y1, ld r);
ld ansprog(ld x, ld y);
ld ansy(ld x);
ld allans();
int main()
{
    freopen("bowling.in", "r", stdin);
    freopen("bowling.out", "w", stdout);
    int i;
    ld ans;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d%d%d", &a[i], &b[i], &r[i]);
    cin >> sx >> sy;
    ans = allans();
    if (ans < 0)
        ans = 0;
    cout << fixed << setprecision(11) << ans << endl;
    return 0;
}

ld ras(ld x, ld y, ld x1, ld y1, ld r)
{
    ld ans = hypot(x - x1, y - y1);
    if (ans > r)
        ans = ans - r;
    return ans;
}

ld ansvec(ld x, ld y, ld x1, ld y1, ld r)
{
    ld dll, dlr, ans, xt, yt, dlt, xx, yy, m1, m2;
    dlt = hypot(x - ld(sx), y - ld(sy));
    xx = (x - ld(sx)) / dlt;
    yy = (y - ld(sy)) / dlt;
    dll = 1.0;
    dlr = 100010.0;
    while (dlr - dll > EPS)
    {
        m1 = dll + (dlr - dll) / 3.0;
        m2 = dlr - (dlr - dll) / 3.0;
        if (ras(ld(sx) + xx * m1, ld(sy) + yy * m1, x1, y1, r) > ras(ld(sx) + xx * m2, ld(sy) + yy * m2, x1, y1, r))
            dll = m1;
        else
            dlr = m2;
    }

    ans = (ras(ld(sx) + xx * dll, ld(sy) + yy * dll, x1, y1, r) + ras(ld(sx) + xx * dlr, ld(sy) + yy * dlr, x1, y1, r)) / 2.0;
    return ans;
}

ld ansprog(ld x, ld y)
{
    int i;
    ld mx = -ld(INF);
    for (i = 0; i < n; i++)
        mx = max(mx, ansvec(x, y, ld(a[i]), ld(b[i]), ld(r[i])));
    //cout << fixed << setprecision(11) << x << ' ' << y << endl;
    return mx;
}

ld ansy(ld x)
{
    ld yl = -1000000010.0, yr = 1000000010.0, m1, m2, ans;
    //cout << fixed << setprecision(11) << x << endl;
    while (yr - yl > EPS)
    {
        m1 = yl + (yr - yl) / 3.0;
        m2 = yr - (yr - yl) / 3.0;
        if (ansprog(x, m1) > ansprog(x, m2))
            yl = m1;
        else
            yr = m2;
    }

    ans = (ansprog(x, yl) + ansprog(x, yr)) / 2.0;
    return ans;

}

ld allans()
{
    ld xl = -1000000010.0, xr = 1000000010.0, m1, m2, ans;
    while (xr - xl > EPS)
    {
        m1 = xl + (xr - xl) / 3.0;
        m2 = xr - (xr - xl) / 3.0;
        if (ansy(m1) > ansy(m2))
            xl = m1;
        else
            xr = m2;
    }

    ans = (ansy(xl) + ansy(xr)) / 2.0;
    return ans;
}

/*
2
0 0 1
4 0 1
2 -1
*/

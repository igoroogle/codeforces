#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI = 3.14159265358979324000;
int n;
ld a[200010], b[200010];

ld len(ld x, ld y, ld x1, ld y1, ld x2, ld y2)
{
    ld a, b, c;
    a = y1 - y2;
    b = x2 - x1;
    c = -(a * x1 + b * y1);
    if ((x - x1)*(x2 - x1)+(y - y1)*(y2 - y1)<=0)
        return sqrt((x - x1)*(x - x1)+(y - y1)*(y - y1));
    else if ((x - x2)*(x1 - x2)+(y - y2)*(y1 - y2) <=0)
        return sqrt((x - x2)*(x - x2) +(y - y2)*(y - y2));
    else
        return abs(a * x + b * y + c) / sqrt(a * a + b * b);
}

int main()
{
    ld r2, r1, d, x, y;
    ll xx, yy, i, n;
    cin >> n >> x >> y;

    for (i = 0; i < n; i++)
        {
            scanf("%I64d %I64d", &xx, &yy);
            a[i] = ld(xx);
            b[i] = ld(yy);
        }

    a[n] = a[0];
    b[n] = b[0];
    r1 = len(x, y, a[0], b[0], a[1], b[1]);
    r2 = hypot(x - a[0], y - b[0]);
    for (i = 1; i < n; i++)
    {
        r1 = min(r1, len(x, y, a[i], b[i], a[i + 1], b[i + 1]));
        r2 = max(r2, hypot(x - a[i], y - b[i]));
    }

    cout << fixed << setprecision(14) << PI * (r2 * r2 - r1 * r1);
    return 0;
}

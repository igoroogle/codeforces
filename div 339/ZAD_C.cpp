#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MX = 2000000001;
const ld PI = 3.14159265358979324000;
string s, ss = "1";
void pram(ld x1, ld y1, ld x2,ld y2, ld &a, ld &b, ld &c)
{
   a = y1 - y2;
   b = x2 - x1;
   c = -(a * x1 + b * y1);
}

ld otr(ld x, ld y, ld x1, ld y1, ld x2, ld y2)
{
   ld a, b, c;
   pram(x1, y1, x2, y2, a, b, c);
   if ((x-x1)*(x2-x1)+(y-y1)*(y2-y1) <= 0)
        return sqrt((x-x1)*(x-x1) +(y-y1)*(y-y1));
   else if ((x-x2)*(x1-x2)+(y-y2)*(y1-y2)<=0)
   return sqrt((x-x2)*(x-x2) +(y-y2)*(y-y2));
   return abs(a*x+b*y+c)/sqrt(a*a+b*b);
}

ld a[200010], b[200010];
int main()
{
    ld r1, r2, x1, y1, x2, y2;
    ll n, i, x, y;
    cin >> n >> x >> y;
    x1 = ld(x);
    y1 = ld(y);
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        a[i] = ld(x);
        b[i] = ld(y);
    }

    a[n] = a[0];
    b[n] = b[0];
    r1 = otr(x1, y1, a[0], b[0], a[1], b[1]);
    r2 = r1;

    for (i = 0; i < n; i++)
    {
        r1 = max(r1, otr(x1, y1, a[i], b[i], a[i + 1], b[i + 1]));
        r2 = min(r2, otr(x1, y1, a[i], b[i], a[i + 1], b[i + 1]));
    }
    cout << fixed << setprecision(13) << PI * r1 * r1 + PI * r2 * r2 << endl;
    return 0;
}

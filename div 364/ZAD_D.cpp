#include<bits/stdc++.h>
#define x firsr
#define y second
#define mp make pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1E-10;
ld toans(ld x);
ll n, l, v1, v2, k;
int main()
{
    cin >> n >> l >> v1 >> v2 >> k;
    n = (n - ll(1)) / k + ll(1);
    ld l1, r1, m1, m2;
    ll i;
    l1 = EPS;
    r1 = ld(l);
    for (i = 0; i < 1000; i++)
    {
        m1 = l1 + (r1 - l1) / ld(3);
        m2 = r1 - (r1 - l1) / ld(3);
        if (toans(m1) > toans(m2))
            l1 = m1;
        else
            r1 = m2;
    }

    cout << fixed << setprecision(8) << toans((l1 + r1) / ld(2)) << endl;
    return 0;
}

ld toans(ld x)
{
    ld c1 = 0, c2, tim = x / ld(v2), sm;
    ll kul = n - ll(1);
    sm = tim;
    c1 = tim * ld(v1);
    c2 = x;
    c2 = min(c2, ld(l));
    while ((kul > 0) && (c1 < c2) && (c2 < ld(l)))
    {
        kul--;
        tim = (c2 - c1) / ld(v2 + v1);
        sm += tim;
        c1 += tim * ld(v1);
        c2 += tim * ld(v1);
        c2 = min(c2, ld(l));
        if (c1 < c2)
        {
            tim = (c2 - c1) / ld(v2 - v1);
            if (c2 + tim * ld(v1) >= l)
            {
                c2 = l + EPS;
                sm += (ld(l) - c1) / v1;
                break;
            }

            sm += tim;
            c1 += tim * ld(v1);
            c2 += tim * ld(v1);
        }
    }

    if (c2 < ld(l))
        sm += (ld(l) - c2) / v1;
    else if (kul > 0)
        sm += (ld(l) - c1) / v1;
    return sm;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //freopen("grants.in", "r", stdin);
    //freopen("grants.out", "w", stdout);
    ll n, t, i, j, g, k, val, val2, zn, zn2, a, b, c, a1, b1, c1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        val = 0;
        a = 0;
        b = 0;
        c = n;
        for (i = 61; i >= 0; i--)
        {
            zn = ll(1) << i;
            if ((val | zn) * ll(3) <= n)
            {
                k = n - ll((val | zn) * ll(3));
                g = 0;
                val2 = ll(val | zn);
                a1 = val2;
                b1 = val2;
                c1 = val2;
                for (j = 61; j >= 0; j--)
                    if (!(val2 & (ll(1) << j)))
                    {
                        zn2 = ll(1) << j;
                        if (zn2 + g <= k)
                        {
                            g += zn2;
                            a1 |= zn2;
                        }

                        if (zn2 + g <= k)
                        {
                            g += zn2;
                            b1 |= zn2;
                        }

                        if (zn2 + g <= k)
                        {
                            g += zn2;
                            c1 |= zn2;
                        }
                    }

                if (g == k)
                {
                    a = a1;
                    b = b1;
                    c = c1;
                    val = val2;
                }
            }
        }
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}

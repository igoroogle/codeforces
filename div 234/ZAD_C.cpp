#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m, x, y, z, p, n1, m1, i, j, x1, y1, xx, yy;
    cin >> n >> m >> x >> y >> z >> p;
    for (i = 0; i < p; i++)
    {
        scanf("%I64d%I64d", &x1, &y1);
        n1 = n;
        m1 = m;
        for (j = 0; j <= x % 4; j++)
        {
            xx = x1;
            yy = y1;
            x1 = yy;
            y1 = n1 - xx + 1;
            swap(n1, m1);
        }

        if (y % 2)
            x1 = n1 - x1 + 1;
        for (j = 0; j <= z % 4; j++)
        {
            xx = x1;
            yy = y1;
            x1 = m1 - yy + 1;
            y1 = xx;
            swap(n1, m1);
        }
        printf("%I64d %I64d\n", x1, y1);
    }
    return 0;
}

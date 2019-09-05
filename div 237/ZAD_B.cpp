#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double a, d, d1, x, y;
    x = 0.0;
    y = 0.0;
    ll n, i, kor = 1, kol;
    cin >> a >> d >> n;
    kol = floor(d / (4.0 * a));
    d -= double(kol) * 4.0 * a;
    for (i = 0; i < n; i++)
    {
        d1 = d;
        for(;;)
        {
            if (kor == 1)
            {
                if (x + d1 < a)
                {
                    x += d1;
                    break;
                }
                else
                {
                    d1 -= a - x;
                    x = a;
                    kor = 2;
                }
            }
            else if (kor == 2)
            {
                if (y + d1 < a)
                {
                    y += d1;
                    break;
                }
                else
                {
                    d1 -= a - y;
                    y = a;
                    kor = 3;
                }
            }
            else if (kor == 3)
            {
                if (x - d1 > 0)
                {
                    x -= d1;
                    break;
                }
                else
                {
                    d1 -= x;
                    x = 0;
                    kor = 4;
                }
            }
            else
            {
                if (y - d1 > 0)
                {
                    y -= d1;
                    break;
                }
                else
                {
                    d1 -= y;
                    y = 0;
                    kor = 1;
                }
            }
        }
        printf("%.8lf %.8lf\n", x, y);
    }
    return 0;
}

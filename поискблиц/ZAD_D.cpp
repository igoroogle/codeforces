#include <bits/stdc++.h>
using namespace std;
int a[17];
int main()
{
    int n = 0, i, t, ans = 0, x, y;
    bool f1, f2;
    cin >> x;
    t = x;
    while (x > 0)
    {
        a[n++] = x % 10;
        x /= 10;
    }

    for (x = 0; x < 9; x++)
        for (y = x + 1; y <= 9; y++)
        {
            for (i = 1; i < n - 1; i++)
            {
                ans += (1 << i) - 1;
                if (x > 0)
                    ans += (1 << i) - 1;
            }

            i = n - 1;
            f1 = 0;
            f2 = 0;
            for(;;)
            {
                if (i == 0)
                {
                    if ((f2) && (a[i] >= x))
                        ans++;
                    if ((f1) && (a[i] >= y))
                        ans++;
                    break;
                }


                if ((x < a[i]) && ((x != 0) || (i < n - 1)))
                {
                    ans += (1 << i);
                    if ((!f2))
                        ans--;
                }

                if ((y < a[i]))
                {
                    ans += (1 << i);
                    if (!f1)
                        ans--;
                }

                if ((a[i] != x) && (a[i] != y))
                    break;
                if (a[i] == x)
                    f1 = 1;
                if (a[i] == y)
                    f2 = 1;
                i--;
            }
        }

    for (i = 1; i <= 9; i++)
    {
        x = i;
        while (x <= t)
        {
            ans++;
            x = x * 10 + i;
        }
    }

    cout << ans << endl;
    return 0;
}

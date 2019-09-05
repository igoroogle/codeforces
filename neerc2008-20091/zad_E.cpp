#include <bits/stdc++.h>
using namespace std;

int w, h, l, k, res;

int main()
{
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);

    cin >> w >> h >> l >> k;

    if (k == 6)
    {
        if (w + h + l == 3)
            cout << 1;
        else
            cout << 0;
    }
    else if (k == 5)
    {
        if (((w > 1) && (h == 1 && l == 1)) || ((h > 1) && (w == 1 && l == 1)) || ((l > 1) && (h == 1 && w == 1)))
            cout << 2;
        else
            cout << 0;
    }
    else if (k == 4)
    {
        if (((w == 1) && (h > 1 && l > 1)) || ((h == 1) && (w > 1 && l > 1)) || ((l == 1) && (h > 1 && w > 1)))
            cout << 4;
        else if (((w > 1) && (h == 1 && l == 1)) || ((h > 1) && (w == 1 && l == 1)) || ((l > 1) && (h == 1 && w == 1)))
            cout << w + h + l - 4;
        else
            cout << 0;
    }
    else if (k == 3)
    {
        if (w > 1 && h > 1 && l > 1)
            cout << 8;
        else
        {
            if ((w == 1) && (h > 1 && l > 1))
                res = (h + l - 4) * 2;
            if ((h == 1) && (w > 1 && l > 1))
                res = (w + l - 4) * 2;
            if ((l == 1) && (w > 1 && h > 1))
                res = (w + h - 4) * 2;

            cout << res;
        }
    }
    else if (k == 2)
    {
        if (w > 1 && h > 1 && l > 1)
            cout << (w + h + l - 6) * 4;
        else
        {
            if ((w == 1) && (h > 1 && l > 1))
                res = (h - 2) * (l - 2);
            if ((h == 1) && (w > 1 && l > 1))
                 res = (w - 2) * (l - 2);
            if ((l == 1) && (w > 1 && h > 1))
                 res = (h - 2) * (w - 2);

            cout << res;
        }
    }
    else if (k == 1)
    {
        if (w > 1 && h > 1 && l > 1)
            cout << (h - 2) * (l - 2) * 2 + (w - 2) * (l - 2) * 2 + (h - 2) * (w - 2) * 2;
        else
            cout << 0;
    }
    else
    {
        if (w > 1 && h > 1 && l > 1)
            cout << (w - 2) * (h - 2) * (l - 2);
        else
            cout << 0;
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int n, m, d[130000], h[130000], i, j, mx = 0, l, r, mm, rr, qq;
    bool er = false;
    cin >> n >> m;
    rr = 1;
    qq = 1;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &d[i], &h[i]);
        if (i > 0 && abs(d[i] - d[i - 1]) < abs(h[i] - h[i - 1]))
            er = 1;
        if (i == 0 && d[i] != 1)
        {
            mx = h[i] + d[i] - 1;
        }
        if (i > 0)
        {
        l = h[i];
        r = 1000000000;
        while (r - l > 1)
        {
            mm = (r + l) / 2;
            if (abs(h[i] - mm) + abs(h[i - 1] - mm) <= d[i] - d[i - 1])
                l = mm;
            else
                r = mm;
        }
        if (abs(h[i] - r) + abs(h[i - 1] - r) <= d[i] - d[i - 1])
            mx = max(mx, r);
        if (abs(h[i] - l) + abs(h[i - 1] - l) <= d[i] - d[i - 1])
            mx = max(mx, l);
        }
        else
            mx = max(mx, h[i]);
    }
    if (d[m - 1] != n)
        mx = max(mx, h[m - 1] + n - d[m - 1]);
    if (er)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << mx;
  return 0;
}















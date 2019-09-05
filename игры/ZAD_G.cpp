#include <bits/stdc++.h>
using namespace std;
const int DL = 161051;
int a[5][10][DL], rig[20][DL], dc[20][DL], lef[20][DL];
int rec(int n, int k, int bit);
int main()
{
    freopen("many-heaps2.in", "r", stdin);
    freopen("many-heaps2.out", "w", stdout);
    int n, k, t, i, j, dec = 0, pv = 0, lv = 0, bit, x;
    cin >> t;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < DL; k++)
                a[i][j][k] = -1;

    for (i = 0; i < DL; i++)
    {
        dec = 1;
        pv = 0;
        lv = i;
        for (j = 0; j < 20; j++)
        {
            dc[j][i] = dec;
            rig[j][i] = pv;
            lef[j][i] = lv;
            pv = (lv % 11) * dec + pv;
            dec *= 11;
            lv /= 11;
        }
    }
    while (t--)
    {
        scanf("%d%d", &n, &k);
        bit = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            bit = bit * 11 + x;
        }

        printf("%d\n", rec(n, k, bit));
    }

    return 0;
}

int rec(int n, int k, int bit)
{
    if (a[n - 1][k - 1][bit] > -1)
        return a[n - 1][k - 1][bit];

    if ((bit / 11 == 0) && (bit % 11 == 1))
    {
        a[n - 1][k - 1][bit] = 0;
        return 0;
    }

    if ((bit / 11 == 0) && (bit % 11 == 0))
    {
        a[n - 1][k - 1][bit] = 1;
        return 1;
    }
    int i, j, ans = 0, st = 0;
    for (i = 1; i <= n; i++)
    {
        st = lef[n - i][bit] % 11;
        for (j = max(0, st - k); j < st; j++)
            if (!rec(n, k, (lef[n - i + 1][bit] * 11 + j) * dc[n - i][bit] + rig[n - i][bit]))
                ans++;
    }

    a[n - 1][k - 1][bit] = ans;
    return ans;
}

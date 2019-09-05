#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[256][256][256], val[256][256][256];
int r[100010], g[100010], b[100010], n, p, vans[100010];
const int INF = 2000000000;

int fun(int i, int j, int k)
{
    if ((i < 0) || (j < 0) || (k < 0))
        return 0;
    return sum[i][j][k];
}

bool check(int x, int y, int z, int v)
{
    int xn = min(255, x + v), yn = min(255, y + v), zn = min(255, z + v), ans;
    ans = sum[xn][yn][zn] - fun(x - 1, yn, zn) - fun(xn, y - 1, zn) - fun(xn, yn, z - 1) + fun(xn, y - 1, z - 1) + fun(x - 1, yn, z - 1)
    + fun(x - 1, y - 1, zn) - fun(x - 1, y - 1, z - 1);
    return (ans < p);
}

int main()
{
    freopen("rgb.in", "r", stdin);
    freopen("rgb.out", "w", stdout);
    int i, j, k, l1, r1, m1, mn = INF, rs = 0, rf = 0, gs = 0, gf = 0, bs = 0, bf = 0, kol = 0;
    cin >> n >> p;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &r[i], &g[i], &b[i]);
        val[r[i]][g[i]][b[i]]++;
    }

    for (i = 0; i < 256; i++)
        for (j = 0; j < 256; j++)
            for (k = 0; k < 256; k++)
            {
                sum[i][j][k] = val[i][j][k] + fun(i - 1, j, k) + fun(i, j - 1, k) + fun(i, j, k - 1) - fun(i, j - 1, k - 1) - fun(i - 1, j, k - 1)
                - fun(i - 1, j - 1, k) + fun(i - 1, j - 1, k - 1);
            }

    for (i = 0; i < 256; i++)
        for (j = 0; j < 256; j++)
            for (k = 0; k < 256; k++)
            {
               l1 = 0;
               r1 = 256;

               while (l1 < r1)
               {
                   m1 = (l1 + r1) / 2;
                   if (check(i, j, k, m1))
                        l1 = m1 + 1;
                   else
                        r1 = m1;
               }

               if ((l1 < mn) && (!check(i, j, k, l1)))
               {
                   mn = l1;
                   rs = i;
                   rf = i + l1;
                   gs = j;
                   gf = j + l1;
                   bs = k;
                   bf = k + l1;
               }

            }

    for (i = 0; i < n; i++)
        if ((r[i] >= rs) && (r[i] <= rf) && (g[i] >= gs) && (g[i] <= gf) && (b[i] >= bs) && (b[i] <= bf))
        {
            kol++;
            vans[kol - 1] = i + 1;
        }
    for (i = 0; i < p; i++)
        printf("%d ", vans[i]);
    return 0;
}

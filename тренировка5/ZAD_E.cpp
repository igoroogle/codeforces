#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[256][256][256], val[256][256][256];
int r[10010], g[100010], b[100010], n, p, vans[100010];
const int INF = 2000000000;
bool check(int x, int y, int z, int v)
{
    int xn = min(255, x + v), yn = min(255, y + v), zn = min(255, z + v);
    ll ans = sum[xn][yn][zn];
    int i = x, j = y, k = z;
    if (i - 1 >= 0)
        ans -= ll(val[i - 1][j][k]);
    else if ((i - 1 >= 0) && (j - 1 >= 0))
        ans -= ll(val[i - 1][j - 1][k]);
    else if ((i - 1 >= 0) && (k - 1 >= 0))
        ans -= ll(val[i - 1][j][k - 1]);
    else if (j - 1 >= 0)
        ans -= ll(val[i][j - 1][k]);
    else if ((j - 1 >= 0) && (k - 1 >= 0))
        ans -= ll(val[i][j - 1][k - 1]);
    else if (k - 1 >= 0)
        ans -= ll(val[i][j][k - 1]);
    if ((i - 1 >= 0) && (j - 1 >= 0) && (k - 1 >= 0))
        ans -= sum[i - 1][j - 1][k - 1];
    if (ans < p)
        return 1;
    return 0;
}
int main()
{
    //freopen("rgb.in", "r", stdin);
    //freopen("rgb.out", "w", stdout);
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
                sum[i][j][k] = val[i][j][k];
                if (i - 1 >= 0)
                    sum[i][j][k] += ll(val[i - 1][j][k]);
                else if ((i - 1 >= 0) && (j - 1 >= 0))
                    sum[i][j][k] += ll(val[i - 1][j - 1][k]);
                else if ((i - 1 >= 0) && (k - 1 >= 0))
                    sum[i][j][k] += ll(val[i - 1][j][k - 1]);
                else if (j - 1 >= 0)
                    sum[i][j][k] += ll(val[i][j - 1][k]);
                else if ((j - 1 >= 0) && (k - 1 >= 0))
                    sum[i][j][k] += ll(val[i][j - 1][k - 1]);
                else if (k - 1 >= 0)
                    sum[i][j][k] += ll(val[i][j][k - 1]);
                if ((i - 1 >= 0) && (j - 1 >= 0) && (k - 1 >= 0))
                    sum[i][j][k] += sum[i - 1][j - 1][k - 1];
            }
    for (i = 0; i < 256; i++)
        for (j = 0; j < 256; j++)
            for (k = 0; k < 256; k++)
            {
               l1 = 0;
               r1 = 259;
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
               if ((i == 254) && (j == 255) && (k == 255))
               {
                   cout << l1 << endl;
                   cout << mn << endl;
                   cout << check(i, j, k, l1) << endl;
               }
            }

    for (i = 0; i < n; i++)
        if ((r[i] >= rs) && (r[i] <= rf) && (g[i] >= gs) && (g[i] <= gf) && (b[i] >= bs) && (b[i] <= bf))
        {
            kol++;
            vans[kol - 1] = i + 1;
        }
    cout << mn << ' ' << rs << ' ' << rf << ' ' << gs << ' ' << gf << ' ' << bs << ' ' << bf << endl;
    cout << check(0, 0, 0, 200) << endl;
    cout << sum[255][255][255] << endl;
    cout << "ans " << sum[253][254][254] << endl;
    for (i = 0; i < p; i++)
        printf("%d ", vans[i]);
    return 0;
}

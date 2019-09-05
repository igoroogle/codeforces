#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[19][262146], bit[262146], a[19], b[19][19];
int bitnull(int val, int ind)
{
    return !(val & (1 << ind));
}
int main()
{
    int i, j, k, m, n, x, y, z;
    ll mx = 0;
    cin >> n >> m >> k;

    for (i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (i = 0; i < k; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        x--;
        y--;
        b[x][y] = max(ll(z), b[x][y]);
    }
   for (i = 0; i < (1 << n); i++)
   {
       j = i;
       while (j > 0)
       {
           bit[i] += ll(j % 2);
           j /= 2;
       }
   }
   for (i = 1; i < (1 << n); i++)
        for (j = 0; j < n; j++)
            dp[j][i] = -1;
   for (i = 0; i < (1 << n); i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                {
                    if (dp[j][i] < 0)
                        continue;
                    if (bit[i] == ll(m))
                        mx = max(mx, dp[j][i]);
                    if (bitnull(i, k))
                        {
                            if (i > 0)
                                dp[k][i | (1 << k)] = max(dp[k][i | (1 << k)], dp[j][i] + a[k] + b[j][k]);
                            else if (i == 0)
                                dp[k][i | (1 << k)] = max(dp[k][i | (1 << k)], dp[j][i] + a[k]);
                        }
                }
    cout << mx << endl;
    return 0;
}

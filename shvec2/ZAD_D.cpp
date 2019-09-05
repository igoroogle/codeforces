#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll d[101][101], kol[101][101], n, m;
ld dp[101][101];
vector<ll> g[101];
void rec(ll i, ll j);
int main()
{
    ll i, j, k, x, y;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            {
                d[i][j] = n + 1;
                dp[i][j] = -1;
            }

    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        d[x][y] = 1;
        d[y][x] = 1;
        kol[x][y]++;
        kol[y][x]++;
    }
    for (i = 0; i < n; i++)
        d[i][i] = 0;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            rec(i, j);
    ld mx = 0, sm;
    for (i = 0; i < n; i++)
    {
        sm = 0;
        for (j = 0; j < g[i].size(); j++)
        {
            x = g[i][j];
            if (d[0][i] + d[x][n - 1] + 1 == d[0][n - 1])
                sm += dp[0][i] * dp[x][n - 1];
            if (d[0][x] + d[x][n - 1] + 1 == d[0][n - 1])
                sm += dp[0][x] * dp[i][n - 1];
            if (d[n - 1][i] + d[x][0] + 1 == d[n - 1][0])
                sm += dp[n - 1][i] * dp[x][0];
            if (d[n - 1][x] + d[x][0] + 1 == d[n - 1][0])
                sm += dp[n - 1][x] * dp[i][0];
        }
        mx = max(mx, sm / dp[0][n - 1]);
    }
    cout << fixed << setprecision(11) << mx << endl;
    return 0;
}
void rec(ll i, ll j)
{
    if (dp[i][j] != -1)
        return;
    dp[i][j] = 1;
    if (i == j)
        return;
    dp[i][j] = kol[i][j];
    if (dp[i][j] > 0)
        return;
    int k;
    for (k = 0; k < n; k++)
        if ((kol[i][k] > 0) && (d[k][j] + 1 == d[i][j]))
        {
            rec(k, j);
            dp[i][j] += ld(dp[k][j]) * ld(kol[i][k]);
        }
    if (dp[i][j] == 0)
        dp[i][j] = 1;
    return;
}

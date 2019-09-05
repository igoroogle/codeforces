#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 203;
const ll MINDL = 100;
const ll INF = 2000000000000000010;
ll dp[DL][DL], dis[DL][DL];
ll a[DL], n, d, xs, ys, xf, yf;
ll rec(ll x, ll y);
int main()
{
    ll i, j, x, y;
    cin >> n >> d;
    for (i = 1; i < n - 1; i++)
        scanf("%I64d", &a[i]);

    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        if (i == 0)
        {
            xs = x;
            ys = y;
        }

        else if (i == n - 1)
        {
            xf = x;
            yf = y;
        }
        dis[x + MINDL][y + MINDL] = a[i];
    }
    for (i = 0; i < DL; i++)
        for (j = 0; j < DL; j++)
            dp[i][j] = -INF;
    dp[xf + MINDL][yf + MINDL] = 0;
    cout << rec(xs, ys) << endl;
    return 0;
}

ll rec(ll x, ll y)
{
    if ((x + MINDL < 0) || (y + MINDL < 0) || (x + MINDL >= DL) || (y + MINDL >= DL))
        return INF;
    if (dp[x + MINDL][y + MINDL] != -INF)
        return dp[x + MINDL][y + MINDL];
    dp[x + MINDL][y + MINDL] = INF;
    ll val = INF;
    if (rec(x + 1, y) < INF)
        val = min(val, rec(x + 1, y) + d - dis[x + MINDL][y + MINDL]);
    if (rec(x - 1, y) < INF)
        val = min(val, rec(x - 1, y) + d - dis[x + MINDL][y + MINDL]);
    if (rec(x, y + 1) < INF)
        val = min(val, rec(x, y + 1) + d - dis[x + MINDL][y + MINDL]);
    if (rec(x, y - 1) < INF)
        val = min(val, rec(x, y - 1) + d - dis[x + MINDL][y + MINDL]);
    dp[x + MINDL][y + MINDL] = val;
    return val;
}

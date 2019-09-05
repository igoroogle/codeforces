#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 1048579;
const ll MINDL = 100;
const ll INF = 2000000000000000010;
ll dp[DL];
struct xyz
{
    int x, y, z;
};

bool comp(xyz a, xyz b)
{
    return (a.y < b.y);
}
xyz a[101];
int main()
{
    int i, j, n, m, x, y, k, m1, val;
    ll b, mn = INF;
    cin >> n >> m >> b;
    for (i = 0; i < (1 << m); i++)
        dp[i] = INF;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x, &k, &m1);
        a[i].x = x;
        a[i].y = k;
        for (j = 0; j < m1; j++)
        {
            scanf("%d", &y);
            a[i].z |= (1 << (y - 1));
        }
    }
    dp[0] = 0;
    sort(a, a + n, comp);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (1 << m); j++)
        {
            if (dp[j] == INF)
                continue;
            val = j | a[i].z;
            dp[val] = min(dp[val], dp[j] + a[i].x);
        }
        if (dp[(1 << m) - 1] < INF)
            mn = min(mn, dp[(1 << m) - 1] + a[i].y * b);
    }
    if (mn == INF) cout << -1 << endl;
    else cout << mn << endl;
    return 0;
}

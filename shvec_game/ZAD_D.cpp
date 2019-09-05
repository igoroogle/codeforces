#include <bits/stdc++.h>
using namespace std;
const int INF = 2E9;
int n, m, a[210], b[25], dp[2048577];
char c[25];
int ans(int bit, int v);

int bitnull(int n, int i)
{
    return bool(n & (1 << i));
}

int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);

    cin >> m;

    for (i = 0; i < m; i++)
        cin >> c[i] >> b[i];

    for (i = 0; i < (1 << m); i++)
        dp[i] = INF;
    cout << ans(0, 0) << endl;
    return 0;
}

int ans(int bit, int v)
{
    if (v >= m)
        return 0;

    if (dp[bit] != INF)
        return dp[bit];

    int i, mx = 0;
    if (b[v] == 1)
        mx = -INF;
    else
        mx = INF;

    for (i = 0; i < m; i++)
        if (!bitnull(bit, i))
        {
            if (c[v] == 'p')
            {
                if (b[v] == 1)
                    mx = a[i] + ans(bit | (1 << i), v + 1);
                else
                    mx = -a[i] + ans(bit | (1 << i), v + 1);
                break;
            }

            else
            {
                if (b[v] == 1)
                    mx = max(mx, ans(bit | (1 << i), v + 1));
                else
                    mx = min(mx, ans(bit | (1 << i), v + 1));
            }
        }

    dp[bit] = mx;
    return mx;
}

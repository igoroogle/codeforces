#include <bits/stdc++.h>
using namespace std;
const int DL = 200010;
const int INF = 1000000000;
const int MX = 77777;
int ranks[DL], parent[DL], sum[DL], val[DL], dp[DL], pr[DL];
int getroot(int v);
void unionv(int u, int v);
pair <int, int> a[DL];
int main()
{
    int n, m, i, j, x, y, u, v, kol1 = 0, kol2 = 0, ans, kol = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        ranks[i] = 1;
        parent[i] = -1;
        sum[i] = 1;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        u = getroot(x);
        v = getroot(y);
        unionv(u, v);
    }

    for (i = 0; i < n; i++)
    {
        u = getroot(i);
        a[i].first = sum[u];
        a[i].second = u;
    }
    sort(a, a + n);
    m = 1;
    for (i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            a[m++] = a[i];
    for (i = 0; i < m; i++)
        val[a[i].first]++;
    ans = INF;
    for (i = 1; i < MX + 1; i++)
        dp[i] = INF;
    for (i = 1; i < MX + 1; i++)
        for (j = 0; j < min(val[i], min(MX, n)); j++)
            pr[kol++] = i;
    for (i = 0; i < kol; i++)
        for (j = min(n, MX); j >= 0; j--)
            if ((j - pr[i] >= 0) && (dp[j - pr[i]] != INF))
                dp[j] = min(dp[j - pr[i]] + 1, dp[j]);
    bool f;
    for (i = 1; i <= min(MX + 1, n); i++)
    {
        j = i;
        f = 1;
        while (j > 0)
        {
            if ((j % 10 != 4) && (j % 10 != 7))
            {
                f = 0;
                break;
            }
            j /= 10;
        }
        if (f)
            ans = min(ans, dp[i]);
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans - 1 << endl;
    return 0;
}

int getroot(int v)
{
    if (parent[v] == -1)
        return v;
    parent[v] = getroot(parent[v]);
    return parent[v];
}

void unionv(int u, int v)
{
    if (u == v)
        return;
    if (ranks[u] > ranks[v])
        {
            parent[v] = u;
            sum[u] += sum[v];
        }
    else if (ranks[v] > ranks[u])
        {
            parent[u] = v;
            sum[v] += sum[u];
        }
    else
    {
        parent[v] = u;
        sum[u] += sum[v];
        ranks[u]++;
    }
}

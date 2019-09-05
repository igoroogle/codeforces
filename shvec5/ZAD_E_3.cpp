#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 200010;
const ll INF = 1000000000;
const ll MX = 77779;
ll ranks[DL], parent[DL], sum[DL], val[DL], dp[DL], pr[DL], cnt[DL];
ll getroot(ll v);
void unionv(ll u, ll v);
pair <ll, ll> a[DL];
int main()
{
    ll n, m, i, j, k, p, x, y, u, v, kol1 = 0, kol2 = 0, ans, kol = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        ranks[i] = 1;
        parent[i] = -1;
        sum[i] = 1;
    }

    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d", &x, &y);
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
    for (i = 1; i < MX; i++)
        dp[i] = INF;
    for (i = 1; i < MX; i++)
    {
        if (!val[i])
            continue;
        cnt[kol] = val[i];
        pr[kol++] = i;
    }

    for (i = 0; i < kol; i++)
    {
        k = 1;
        p = 0;
        while (p < cnt[i])
        {
            if (p + k > cnt[i])
                k = cnt[i] - p;
            p += k;
            for (j = MX - 1; j >= 0; j--)
                if ((j - k * pr[i] >= 0) && (dp[j - k * pr[i]] != INF))
                    dp[j] = min(dp[j], dp[j - k * pr[i]] + k);
            k *= 2;
        }
    }

    bool f;
    for (i = 1; i < min(MX, n + 1); i++)
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

ll getroot(ll v)
{
    if (parent[v] == -1)
        return v;
    parent[v] = getroot(parent[v]);
    return parent[v];
}

void unionv(ll u, ll v)
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

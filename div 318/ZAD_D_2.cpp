#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll DL = 300005;
ll dp[DL], nat[DL], nat2[DL], hor[DL], n;
pair <ll, ll> a[DL], b[DL];
ll ans();
int main()
{
    ll q, i, s, x, y;
    cin >> n >> q;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &a[i].first);
        a[i].second = i;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%I64d", &b[i].first);
        b[i].second = i;
    }

    sort(a, a + n);
    sort(b, b + n);
    reverse(a, a + n);
    reverse(b, b + n);
    for (i = 0; i < n; i++)
    {
        nat[a[i].second] = i;
        nat2[b[i].second] = i;
    }
    for (i = 0; i < n; i++)
        hor[i] = nat2[a[i].second];
    for (i = 0; i < q; i++)
    {
        scanf("%I64d%I64d", &x, &y);
        x = nat[x - 1];
        y = nat[y - 1];
        swap(hor[x], hor[y]);
        printf("%I64d\n", ans());
    }
    return 0;
}

ll ans()
{
    ll s = 0, i, l = 2, val1, val2;
    dp[0] = 0;
    for (i = 0; i < n; i++)
    {
        dp[i + 1] = -1;
        if ((hor[i] != i) && (dp[i] != -1))
            dp[i + 1] = dp[i] + b[i].first * a[i].first;
        if ((i - 1 >= 0) && (hor[i - 1] != i) && (hor[i] != i - 1) && (dp[i - 1] != -1))
            dp[i + 1] = max(dp[i + 1], dp[i - 1] + a[i].first * b[i - 1].first + a[i - 1].first * b[i].first);
        if ((i - 2 >= 0) && (dp[i - 2] != -1))
        {
            if ((hor[i - 2] != i) && (hor[i - 1] != i - 2) && (hor[i] != i - 1))
                dp[i + 1] = max(dp[i + 1], dp[i - 2] + a[i - 2].first * b[i].first + a[i - 1].first * b[i - 2].first + a[i].first * b[i - 1].first);
            if ((hor[i - 2] != i) && (hor[i - 1] != i - 1) && (hor[i] != i - 2))
                dp[i + 1] = max(dp[i + 1], dp[i - 2] + a[i - 2].first * b[i].first + a[i - 1].first * b[i - 1].first + a[i].first * b[i - 2].first);
            if ((hor[i - 2] != i - 1) && (hor[i - 1] != i) && (hor[i] != i - 2))
                dp[i + 1] = max(dp[i + 1], dp[i - 2] + a[i - 2].first * b[i - 1].first + a[i - 1].first * b[i].first + a[i].first * b[i - 2].first);
        }
    }
    return dp[n];
}

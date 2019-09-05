#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 300001;
int nat[DL], nat2[DL], hor[DL], a[DL], b[DL];
ll dp[DL];
pair <int, int> a1[DL], b1[DL];
int main()
{
    int q, i, j, s, x, y, n;
    cin >> n >> q;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a1[i].first);
        a1[i].second = i;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &b1[i].first);
        b1[i].second = i;
    }

    sort(a1, a1 + n);
    sort(b1, b1 + n);
    reverse(a1, a1 + n);
    reverse(b1, b1 + n);
    for (i = 0; i < n; i++)
    {
        nat[a1[i].second] = i;
        nat2[b1[i].second] = i;
    }
    for (i = 0; i < n; i++)
        hor[i] = nat2[a1[i].second];
    for (i = 0; i < n; i++)
    {
        a[i] = a1[i].first;
        b[i] = b1[i].first;
    }
    for (j = 0; j < q; j++)
    {
        scanf("%d%d", &x, &y);
        x = nat[x - 1];
        y = nat[y - 1];
        swap(hor[x], hor[y]);
        dp[0] = 0;
        for (i = 0; i < n; i++)
        {
            dp[i + 1] = -1;
            if ((hor[i] != i) && (dp[i] != -1))
                dp[i + 1] = dp[i] + ll(b[i]) * ll(a[i]);
            if ((i - 1 >= 0) && (hor[i - 1] != i) && (hor[i] != i - 1) && (dp[i - 1] != -1))
                dp[i + 1] = max(dp[i + 1], dp[i - 1] + ll(a[i]) * ll(b[i - 1]) + ll(a[i - 1]) * ll(b[i]));
            if ((i - 2 >= 0) && (dp[i - 2] != -1))
            {
                if ((hor[i - 2] != i) && (hor[i - 1] != i - 2) && (hor[i] != i - 1))
                    dp[i + 1] = max(dp[i + 1], dp[i - 2] + ll(a[i - 2]) * ll(b[i]) + ll(a[i - 1]) * ll(b[i - 2]) + ll(a[i]) * ll(b[i - 1]));
                if ((hor[i - 2] != i) && (hor[i - 1] != i - 1) && (hor[i] != i - 2))
                    dp[i + 1] = max(dp[i + 1], dp[i - 2] + ll(a[i - 2]) * ll(b[i]) + ll(a[i - 1]) * ll(b[i - 1]) + ll(a[i]) * ll(b[i - 2]));
                if ((hor[i - 2] != i - 1) && (hor[i - 1] != i) && (hor[i] != i - 2))
                    dp[i + 1] = max(dp[i + 1], dp[i - 2] + ll(a[i - 2]) * ll(b[i - 1]) + ll(a[i - 1]) * ll(b[i]) + ll(a[i]) * ll(b[i - 2]));
            }
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}


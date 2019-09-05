#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int DL = 300001;
int nat[DL], nat2[DL], hor[DL], a[DL], b[DL];
ll dp[DL], val0[DL], val1[DL], val2[DL], val3[DL], val4[DL];
pair <int, int> a1[DL], b1[DL];
int main()
{
    int q, i, j, s, x, y, n;
    ll v1, v2, v3, v4, v;
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
    for (i = 0; i < n; i++)
    {
        if (i - 2 >= 0)
            val0[i] = ll(a[i]) * ll(b[i - 2]);
        if (i - 1 >= 0)
            val1[i] = ll(a[i]) * ll(b[i - 1]);
        val2[i] = ll(a[i]) * ll(b[i]);
        if (i + 1 < n)
            val3[i] = ll(a[i]) * ll(b[i + 1]);
        if (i + 2 < n)
            val4[i] = ll(a[i]) * ll(b[i + 2]);
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
            v1 = v2 = v3 = v4 = v = -1;
            v = -1;
            if ((hor[i] != i) && (dp[i] != -1))
                v = dp[i] + val2[i];
            if ((i - 1 >= 0) && (hor[i - 1] != i) && (hor[i] != i - 1) && (dp[i - 1] != -1))
                v1 = dp[i - 1] + val1[i] + val3[i - 1];
            if ((i - 2 >= 0) && (dp[i - 2] != -1))
            {
                if ((hor[i - 2] != i) && (hor[i - 1] != i - 2) && (hor[i] != i - 1))
                    v2 = dp[i - 2] + val4[i - 2] + val1[i - 1] + val1[i];
                if ((hor[i - 2] != i) && (hor[i - 1] != i - 1) && (hor[i] != i - 2))
                    v3 = dp[i - 2] + val4[i - 2] + val2[i - 1] + val0[i];
                if ((hor[i - 2] != i - 1) && (hor[i - 1] != i) && (hor[i] != i - 2))
                    v4 = dp[i - 2] + val3[i - 2] + val3[i - 1] + val0[i];
            }
            if (v1 > v)
                v = v1;
            if (v2 > v)
                v = v2;
            if (v3 > v)
                v = v3;
            if (v4 > v)
                v = v4;
            dp[i + 1] = v;
        }
        printf("%I64d\n", dp[n]);
    }
    return 0;
}

